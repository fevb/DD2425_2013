; Auto-generated. Do not edit!


(cl:in-package differential_drive-msg)


;//! \htmlinclude Size.msg.html

(cl:defclass <Size> (roslisp-msg-protocol:ros-message)
  ((r
    :reader r
    :initarg :r
    :type cl:float
    :initform 0.0)
   (b
    :reader b
    :initarg :b
    :type cl:float
    :initform 0.0))
)

(cl:defclass Size (<Size>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Size>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Size)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name differential_drive-msg:<Size> is deprecated: use differential_drive-msg:Size instead.")))

(cl:ensure-generic-function 'r-val :lambda-list '(m))
(cl:defmethod r-val ((m <Size>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader differential_drive-msg:r-val is deprecated.  Use differential_drive-msg:r instead.")
  (r m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <Size>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader differential_drive-msg:b-val is deprecated.  Use differential_drive-msg:b instead.")
  (b m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Size>) ostream)
  "Serializes a message object of type '<Size>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'r))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'b))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Size>) istream)
  "Deserializes a message object of type '<Size>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'b) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Size>)))
  "Returns string type for a message object of type '<Size>"
  "differential_drive/Size")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Size)))
  "Returns string type for a message object of type 'Size"
  "differential_drive/Size")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Size>)))
  "Returns md5sum for a message object of type '<Size>"
  "e3a98497364ff6bb0499d0c2310cde71")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Size)))
  "Returns md5sum for a message object of type 'Size"
  "e3a98497364ff6bb0499d0c2310cde71")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Size>)))
  "Returns full string definition for message of type '<Size>"
  (cl:format cl:nil "float32 r~%float32 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Size)))
  "Returns full string definition for message of type 'Size"
  (cl:format cl:nil "float32 r~%float32 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Size>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Size>))
  "Converts a ROS message object to a list"
  (cl:list 'Size
    (cl:cons ':r (r msg))
    (cl:cons ':b (b msg))
))
