/* Auto-generated by genmsg_cpp for file /home/ghaessig/fuerte_workspace/sandbox/differential_drive/msg/Pose.msg */
#ifndef DIFFERENTIAL_DRIVE_MESSAGE_POSE_H
#define DIFFERENTIAL_DRIVE_MESSAGE_POSE_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"


namespace differential_drive
{
template <class ContainerAllocator>
struct Pose_ {
  typedef Pose_<ContainerAllocator> Type;

  Pose_()
  : timestamp(0.0)
  , x(0.0)
  , y(0.0)
  , theta(0.0)
  {
  }

  Pose_(const ContainerAllocator& _alloc)
  : timestamp(0.0)
  , x(0.0)
  , y(0.0)
  , theta(0.0)
  {
  }

  typedef double _timestamp_type;
  double timestamp;

  typedef double _x_type;
  double x;

  typedef double _y_type;
  double y;

  typedef double _theta_type;
  double theta;


  typedef boost::shared_ptr< ::differential_drive::Pose_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::differential_drive::Pose_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Pose
typedef  ::differential_drive::Pose_<std::allocator<void> > Pose;

typedef boost::shared_ptr< ::differential_drive::Pose> PosePtr;
typedef boost::shared_ptr< ::differential_drive::Pose const> PoseConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::differential_drive::Pose_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::differential_drive::Pose_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace differential_drive

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::differential_drive::Pose_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::differential_drive::Pose_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::differential_drive::Pose_<ContainerAllocator> > {
  static const char* value() 
  {
    return "c291245622dd995c9f51767cfe3ea505";
  }

  static const char* value(const  ::differential_drive::Pose_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xc291245622dd995cULL;
  static const uint64_t static_value2 = 0x9f51767cfe3ea505ULL;
};

template<class ContainerAllocator>
struct DataType< ::differential_drive::Pose_<ContainerAllocator> > {
  static const char* value() 
  {
    return "differential_drive/Pose";
  }

  static const char* value(const  ::differential_drive::Pose_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::differential_drive::Pose_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float64 timestamp\n\
float64 x\n\
float64 y\n\
float64 theta\n\
\n\
";
  }

  static const char* value(const  ::differential_drive::Pose_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::differential_drive::Pose_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::differential_drive::Pose_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.timestamp);
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.theta);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Pose_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::differential_drive::Pose_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::differential_drive::Pose_<ContainerAllocator> & v) 
  {
    s << indent << "timestamp: ";
    Printer<double>::stream(s, indent + "  ", v.timestamp);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "theta: ";
    Printer<double>::stream(s, indent + "  ", v.theta);
  }
};


} // namespace message_operations
} // namespace ros

#endif // DIFFERENTIAL_DRIVE_MESSAGE_POSE_H
