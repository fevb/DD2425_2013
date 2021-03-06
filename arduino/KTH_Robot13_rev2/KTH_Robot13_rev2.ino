/*
 *
 * KTH_Robot13_rev2.ino
 * --------------------
 * Copyright : (c) 2013, Germain Haessig <germain.haessig@ens-cachan.fr>
 * Licence   : BSD3
 * Device target : Arduino Mega 2560 Rev3
 * Shields : | Official ArduinoMotorShield
 *           | Home made KTHDD2425 board
 * 
 * Main embedded project for KTH DD2425
 *
 * Speed regulation is done each "/motion/Speed" callback.
 * Don't forget to initialize the controller values, and your robot's size
 * by using the "/human/Parameters" topic 
 *
 * Subscribes on topics :
 *      | "/motion/Speed"        to receive speed instructions (rad/s)
 *      | "/human/Parameters"    to receive parameters
 *      | "/actuator/Servo"      to receive servo desired position
 *
 * Publishes on topics :
 *      | "/motion/Odometry"      send odometry
 *      | "/sensors/ADC"          send ADC values, including battery voltage
 */


#include <ros.h>
#include <differential_drive/Speed.h>
#include <differential_drive/Odometry.h>
#include <differential_drive/Encoders.h>
#include <differential_drive/AnalogC.h>
#include <differential_drive/Params.h>
#include <differential_drive/Servomotors.h>
#include <std_msgs/Header.h>

#include <stdint.h>

#include <Motors.h>
#include <math.h>

#include <Servo.h> 

#include <music.h> 

/* PinOut definition */
#define ChA_Dir 12
#define ChA_Pwm 3
#define ChA_Brk 9
#define ChA_CFb A0

#define ChB_Dir 13
#define ChB_Pwm 11
#define ChB_Brk 8
#define ChB_CFb A1

#define ChA_Encoder1 20
#define ChA_Encoder2 21

#define ChB_Encoder1 18
#define ChB_Encoder2 19

#define N 10 // Averaging of measured speed with the N last values

/* Battery monitoring const */
#define seuil_cell 3.6
#define seuil_batt 10.8

int led_pin[6] = {38,40,42,44,46,48};

/* Motor objects creation */
/* Please refer to "Motors.h" for further informations */
Motors MotorA(ChA_Dir,ChA_Pwm,ChA_Brk,ChA_CFb);  // schotch jaune
Motors MotorB(ChB_Dir,ChB_Pwm,ChB_Brk,ChB_CFb);

/* Servomotors definition */
Servo servo[8];
char servo_pin[] = {22,24,26,28,30,32,34,36};

/* Lot of global variables (nasty) */
float W1_cons = 0;
float W2_cons = 0;

float r = 38.9E-3 ;
float B = 0.1867 ;
float r_r = 0.5*0.0777;
float r_l = 0.5*0.0779;

float Te = 10*1E-3 ;

float V_lin = 0;
float V_rot = 0;

float x=0;
float y=0;
float theta=0;

int encoder1, encoder1_old ;
int encoder1_loc,encoder2_loc ;
int encoder2, encoder2_old ;

unsigned long time,time_old;
unsigned long t_enc, t_enc_old;
unsigned long wdtime ;

int cpt = 0;

/* Specific parameters for NL control */ 
//#define NLCTRL // comment to use a classic Proportional-Integral *speed* control
#ifdef NLCTRL
float x_ghost=0;
float y_ghost=0;
float theta_ghost=0;
float z1,z2,z3;
float V_lin_ghost,V_rot_ghost;
float u1,u2;
int k1=10;k2=150;k3=80;
#endif


/* ROS Use */
ros::NodeHandle  nh;

differential_drive::Encoders imlost ;
differential_drive::Odometry odom ;
differential_drive::AnalogC Amsg ;

ros::Publisher pubEnc("/motion/Encoders", &imlost);  // Create a publisher to "/motion/Encoders" topic
ros::Publisher pubOdom("/motion/Odometry", &odom);  // Create a publisher to "/motion/Odometry" topic
ros::Publisher sensor("/sensors/ADC", &Amsg);  // Create a publisher to "/sensors/ADC" topic

/* Subscriber Callback */
void messageSpeed( const differential_drive::Speed& cmd_msg){
  static int i = 0;
  static float array1[N],array2[N];
  static float loc1=0,loc2=0;
  wdtime = millis() ;  // store the time for Watchdog
  /* get the time from message header */
  time_old = time ;  
  time = cmd_msg.header.stamp.nsec ;
  if(time>time_old)	{
    Te = (time - time_old)*1E-9 ;
  }
  else	{
    Te = (1E9 + time - time_old)*1E-9;
  }
  
  /* get the speed from message */
  W1_cons = cmd_msg.W1 ;
  W2_cons = cmd_msg.W2 ;
  
  /* Control loop */
  encoder1_loc = encoder1 ;
  encoder2_loc = encoder2 ;

  imlost.encoder1 = encoder1;
  imlost.encoder2 = encoder2;
  imlost.delta_encoder1 = encoder1_loc-encoder1_old ;
  imlost.delta_encoder2 = encoder2_loc-encoder2_old ;
  
  /* get the time since last call */
  t_enc_old = t_enc ;  
  t_enc = millis() ;

  imlost.timestamp = t_enc - t_enc_old ;
  pubEnc.publish(&imlost);
  
  MotorA.Read_speed(encoder1_loc,encoder1_old,Te);
  MotorB.Read_speed(encoder2_loc,encoder2_old,Te);
  
  /* Compute odometry */
  V_lin = 1.0/2*(r_r*MotorA._speed-r_l*MotorB._speed);
  V_rot = 1.0/B*(r_r*MotorA._speed+r_l*MotorB._speed);
  
  // Speed averaging
  array1[i]=V_lin;
  array2[i]=V_rot;
  
  if(i<N-1)  {i++;}
  else  {i=0;}
  
  for(int k=0;k<N;k++)  {
    loc1+=array1[k];
    loc2+=array2[k];
  }
  
  V_lin = loc1/N;
  V_rot = loc2/N;
  
  loc1=0;
  loc2=0;
  
  theta+= V_rot*Te;
  x+= V_lin*Te*cos(theta);
  y+= V_lin*Te*sin(theta);
  
  
  
  #ifdef NLCTRL 
  /* Compute ghost position */
  V_lin_ghost = r/2*(W1_cons+W2_cons);
  V_rot_ghost = r/B*(W2_cons-W1_cons);
  
  theta_ghost+= V_rot_ghost*Te;
  x_ghost+= V_lin_ghost*Te*cos(theta_ghost);
  y_ghost+= V_lin_ghost*Te*sin(theta_ghost);
  
  /* Will try to follow ghost */
  z1 = (x-x_ghost)*cos(theta_ghost)+(y-y_ghost)*sin(theta_ghost);
  z2 = -(x-x_ghost)*sin(theta_ghost)+(y-y_ghost)*cos(theta_ghost);
  z3 = tan(theta-theta_ghost);
  
  u1 = -k1*abs(V_lin)*(z1+z2+z3);
  u2 = -k2*V_lin*z2-k3*abs(V_lin)*z3;
  
  V_lin_ghost = (u1+V_lin)/cos(theta-theta_ghost);
  V_rot_ghost = u2*(cos(theta-theta_ghost))^2+V_rot;
  
  W1_cons = 1/r*V_lin_ghost+B/(2*r)*V_rot_ghost;
  W2_cons = 1/r*V_lin_ghost-B/(2*r)*V_rot_ghost;
  
  /*
  W1_cons = 1/r*V_lin_ghost+B/(2*r)*V_rot_ghost;
  W2_cons = 1/r*V_lin_ghost-B/(2*r)*V_rot_ghost;
  */
  #endif
  
  MotorA.Speed_regulation(W1_cons,Te,encoder1_loc,encoder1_old);
  MotorB.Speed_regulation(-W2_cons,Te,encoder2_loc,encoder2_old);
  
  if(cpt<10)  {cpt++;}
  else  {
    cpt = 0;
    
    /* Publish Odometry */
    odom.x = x ;
    odom.y = y;
    odom.theta = theta ;       
    
    /* Publish Odometry and sensors value */
    pubOdom.publish(&odom);
  }
  
  /* Store encoders value */
  encoder1_old = encoder1_loc ;
  encoder2_old = encoder2_loc ; 
}

void messageParameters(const differential_drive::Params& params)  {
  MotorA.Set_control_parameters(params.K,params.KI,params.INT_MAX,params.ticks);
  MotorB.Set_control_parameters(params.K,params.KI,params.INT_MAX,params.ticks);
  r = params.r;
  r_r = params.r_r;
  r_l = params.r_l;
  B = params.B;
}

void messageServo(const differential_drive::Servomotors& params)  {
  for(int i=0;i<8;i++) {
           servo[i].write(params.servoangle[i]);
  }
}

/* Create Subscriber to "/motion/Speed" topic. Callback function is messageSpeed */
ros::Subscriber<differential_drive::Speed> subSpeed("/motion/Speed", &messageSpeed);

/* Create Subscriber to "/actuator/Servo" topic. Callback function is messageServo */
ros::Subscriber<differential_drive::Servomotors> subServo("/actuator/Servo", &messageServo);

/* Create Subscriber to "/motion/Parameters" topic. Callback function is messageParameters */
ros::Subscriber<differential_drive::Params> subParam("/motion/Parameters", &messageParameters);

void hello_world()  {
  for(int m=0;m<6;m++)  {
      digitalWrite(led_pin[m],HIGH);
      delay(50);
      digitalWrite(led_pin[m],LOW);
  }
  for(int m=4;m>=0;m--)  {
      digitalWrite(led_pin[m],HIGH);
      delay(50);
      digitalWrite(led_pin[m],LOW);
  }
  tone(7,700,50);
  //play_starwars();
  //play_tetris();
  
}
  
void setup()  {  
            
         /* Set the motors in stby */  
         MotorA.Set_speed(0);
         MotorB.Set_speed(0);
         
         /* Set the good parameters */
         MotorA.Set_control_parameters(5, 0, 3, 1000);
         MotorB.Set_control_parameters(5, 0, 3, 1000);
         
         /* Define interruptions, on changing edge */
         attachInterrupt(3,interrupt1,CHANGE);  // A
         attachInterrupt(2,interrupt2,CHANGE);  // A
         attachInterrupt(5,interrupt4,CHANGE);  // B
         attachInterrupt(4,interrupt3,CHANGE);  // B
         
         /* define the outputs pins */
         for(int i=0;i<6;i++) {
           pinMode(led_pin[i],OUTPUT);
         }
         pinMode(7,OUTPUT);
         
         
         /* Configure servomotors pins */
         for(int i=0;i<8;i++) {
           servo[i].attach(servo_pin[i]);
           
         }
         
         /* Initialize ROS stuff */
         nh.initNode();  // initialize node
         
         nh.advertise(pubEnc);  // advertise on pubEnc
         nh.advertise(pubOdom);  // advertise on pubOdom         
         nh.advertise(sensor);  // advertise on sensor
         
         nh.subscribe(subSpeed);  // Subscribe 
         nh.subscribe(subServo);  // Subscribe 
         nh.subscribe(subParam);  // Subscribe 
         
         /* Advertise booting */
         hello_world();
         
         servo[0].write(0);
         delay(1000);
         servo[0].write(180);
}



/*****************************
* Main Loop 
*
* Watchdog timer : if no message recieved during 2s, set the motors in stby,
* computer may have crashed.
******************************/
void loop()  {
  static unsigned long t;
  static unsigned long t_ADC;
  static boolean low_batt = false ;
  nh.spinOnce();
  /* Watchdog timer */
  if(millis()-wdtime > 2000)  { 
    MotorA.Set_speed(0);
    MotorB.Set_speed(0);
    wdtime = millis();
  }
  

  /* Read IR sensors value every 100ms */
  if(millis()-t_ADC>100)
  { 
    Amsg.ch1 = analogRead(A8);
    Amsg.ch2 = analogRead(A9);
    Amsg.ch3 = analogRead(A10);
    Amsg.ch4 = analogRead(A11);
    Amsg.ch5 = analogRead(A12);
    Amsg.ch6 = analogRead(A13);
    Amsg.ch7 = analogRead(A14);
    Amsg.ch8 = analogRead(A15);  
    
    /* Publish sensor value */
    sensor.publish(&Amsg);
    t_ADC = millis();
  }

    if(millis()-t > 1000)  {
    float v1 = analogRead(A7)*0.0049*1.5106;
    float v2 = analogRead(A6)*0.0049*2.9583;
    float v3 = analogRead(A5)*0.0049*2.9583;
    
    Amsg.cell1 = v1;
    Amsg.cell2 = v2 - v1; 
    Amsg.cell3 = v3 - v2;
    Amsg.on_batt = digitalRead(10);
    
    for(int m=0;m<floor((v3-seuil_batt)*4);m++)  {
      digitalWrite(led_pin[m],HIGH);
    }
    for(int m=floor((v3-seuil_batt)*4);m<6;m++)  {
      digitalWrite(led_pin[m],LOW);
    }
    
    if((Amsg.cell1<seuil_cell || Amsg.cell2<seuil_cell || Amsg.cell3<seuil_cell) && v1>2)  {
      low_batt = true ;
    }
    
    if(low_batt && ((Amsg.cell1>seuil_cell+0.2 || Amsg.cell2>seuil_cell+0.2 || Amsg.cell3>seuil_cell+0.2) || v1<2))  {
      low_batt = false;
    }
    
    if(low_batt)  {
      tone(7,440,500); 
    }
    
    t = millis();
  }
    
}

/*********************************************
 *
 *  Interruption subroutines
 *  Called each changing edge of an encoder
 *
 *********************************************/

void interrupt2() {
  if(digitalRead(ChA_Encoder2))
  {
    if (digitalRead(ChA_Encoder1))  encoder1--;
    else                  encoder1++;
  }
   else
  {
    if (!digitalRead(ChA_Encoder1)) encoder1--;
    else                  encoder1++;
  }
}





void interrupt1() {
  if(digitalRead(ChA_Encoder1))
  {
    if (!digitalRead(ChA_Encoder2)) encoder1--;
    else                  encoder1++;
  }
  else
  {
    if (digitalRead(ChA_Encoder2))  encoder1--;
    else                  encoder1++;
  }
}

void interrupt4() {
  if(digitalRead(ChB_Encoder2))
  {
    if (digitalRead(ChB_Encoder1))  encoder2--;
    else                  encoder2++;
  }
   else
  {
    if (!digitalRead(ChB_Encoder1)) encoder2--;
    else                  encoder2++;
  }
}





void interrupt3() {
  if(digitalRead(ChB_Encoder1))
  {
    if (!digitalRead(ChB_Encoder2)) encoder2--;
    else                  encoder2++;
  }
  else
  {
    if (digitalRead(ChB_Encoder2))  encoder2--;
    else                  encoder2++;
  }
}


// -----------------------------------------------------

/* END OF FILE */


