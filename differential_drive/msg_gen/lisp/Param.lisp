; Auto-generated. Do not edit!


(cl:in-package differential_drive-msg)


;//! \htmlinclude Param.msg.html

(cl:defclass <Param> (roslisp-msg-protocol:ros-message)
  ((k
    :reader k
    :initarg :k
    :type cl:float
    :initform 0.0)
   (ki
    :reader ki
    :initarg :ki
    :type cl:float
    :initform 0.0)
   (int_max
    :reader int_max
    :initarg :int_max
    :type cl:float
    :initform 0.0))
)

(cl:defclass Param (<Param>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Param>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Param)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name differential_drive-msg:<Param> is deprecated: use differential_drive-msg:Param instead.")))

(cl:ensure-generic-function 'k-val :lambda-list '(m))
(cl:defmethod k-val ((m <Param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader differential_drive-msg:k-val is deprecated.  Use differential_drive-msg:k instead.")
  (k m))

(cl:ensure-generic-function 'ki-val :lambda-list '(m))
(cl:defmethod ki-val ((m <Param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader differential_drive-msg:ki-val is deprecated.  Use differential_drive-msg:ki instead.")
  (ki m))

(cl:ensure-generic-function 'int_max-val :lambda-list '(m))
(cl:defmethod int_max-val ((m <Param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader differential_drive-msg:int_max-val is deprecated.  Use differential_drive-msg:int_max instead.")
  (int_max m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Param>) ostream)
  "Serializes a message object of type '<Param>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'k))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ki))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'int_max))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Param>) istream)
  "Deserializes a message object of type '<Param>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'k) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ki) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'int_max) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Param>)))
  "Returns string type for a message object of type '<Param>"
  "differential_drive/Param")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Param)))
  "Returns string type for a message object of type 'Param"
  "differential_drive/Param")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Param>)))
  "Returns md5sum for a message object of type '<Param>"
  "583e9b7129e1eeaaa3a32940d81f7e97")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Param)))
  "Returns md5sum for a message object of type 'Param"
  "583e9b7129e1eeaaa3a32940d81f7e97")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Param>)))
  "Returns full string definition for message of type '<Param>"
  (cl:format cl:nil "float32 k~%float32 ki~%float32 int_max~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Param)))
  "Returns full string definition for message of type 'Param"
  (cl:format cl:nil "float32 k~%float32 ki~%float32 int_max~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Param>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Param>))
  "Converts a ROS message object to a list"
  (cl:list 'Param
    (cl:cons ':k (k msg))
    (cl:cons ':ki (ki msg))
    (cl:cons ':int_max (int_max msg))
))
