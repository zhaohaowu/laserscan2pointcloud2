
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <laser_geometry/laser_geometry.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/LaserScan.h>

class LaserScan2PointCloud2{
	private:
		ros::NodeHandle n;
		laser_geometry::LaserProjection transformer;
		tf::TransformListener listener;
		ros::Publisher pub;
		ros::Subscriber sub;
	public:
		LaserScan2PointCloud2();
		void callback(const sensor_msgs::LaserScan::ConstPtr& scan);
};
