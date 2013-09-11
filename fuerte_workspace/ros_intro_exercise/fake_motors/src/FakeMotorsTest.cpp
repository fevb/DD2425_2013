#include "ros/ros.h"
#include <std_msgs/Int32.h>
#include <differential_drive/PWM.h>
#include <differential_drive/Encoders.h>
#include <string.h>

using namespace differential_drive;
ros::Subscriber	enc_sub;
ros::Publisher	pwm_pub;

//Callback function for the "/encoder" topic. Prints the enconder value and randomly changes the motorspeed.
void receive_encoder(const Encoders::ConstPtr &msg)
{
	int right = msg->delta_encoder2;
	int left = msg->delta_encoder1;
	int timestamp = msg->timestamp;
	printf("%d:got encoder L:%d , false R:%d\n",timestamp,left,right);
	PWM pwm;
	pwm.PWM1	= int(255*(0.5f-float(rand()%1000)/1000.0f)*2.0f);//random motorspeed[-255,255]
	pwm.PWM2	= int(255*(0.5f-float(rand()%1000)/1000.0f)*2.0f);//random motorspeed[-255,255]
	pwm_pub.publish(pwm);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "FakeMotorsTest");//Creates a node named "FakeMotorsTest"
	ros::NodeHandle n;
	enc_sub = n.subscribe("/motors/encoders", 1000, receive_encoder);//when "/encoder" topic is revieved call recive_encoder function
	pwm_pub = n.advertise<PWM>("/motors/pwm", 100000);//used to publish a topic that changes the motorspeed

	ros::Rate loop_rate(100);
	//The loop randomly changes the intervall with wich the "/encoder" topic is published.
	
	struct timeval start, end;
	while(ros::ok()){

		loop_rate.sleep();
		ros::spinOnce();

	}
	return 0;
}
