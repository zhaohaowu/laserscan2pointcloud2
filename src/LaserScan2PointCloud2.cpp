#include "LaserScan2PointCloud2.h"

LaserScan2PointCloud2::LaserScan2PointCloud2(){
	sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 100, &LaserScan2PointCloud2::callback, this);
	pub = n.advertise<sensor_msgs::PointCloud2>("/cloud2", 100);
	listener.setExtrapolationLimit(ros::Duration(0.1));
}

void LaserScan2PointCloud2::callback(const sensor_msgs::LaserScan::ConstPtr& scan){
	sensor_msgs::PointCloud2 cloud2;
	transformer.transformLaserScanToPointCloud("laser", *scan, cloud2, listener);
	pub.publish(cloud2);
}

int main(int argc, char** argv){
	ros::init(argc, argv, "LaserScan2PointCloud2");
    LaserScan2PointCloud2 LaserScan2PointCloud2;
    ros::spin();
    return 0;
}
