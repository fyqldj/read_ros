#include <iostream>
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

void imuCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    // 处理IMU数据，这里只是简单地打印数据到命令行
    std::cout<<"Received Header data: "<<std::endl;
    std::cout << "    uint32 seq: " << msg->header.seq << std::endl;
    std::cout << "    time stamp: " << msg->header.stamp << std::endl;
    std::cout << "    string frame_id: " << msg->header.frame_id << std::endl;
    std::cout<<"Received ODOM data: Point point (x, y, z)"<<std::endl;
    std::cout << "    float64 x: " << msg->pose.pose.position.x << std::endl;
    std::cout << "    float64 y: " << msg->pose.pose.position.y << std::endl;
    std::cout << "    float64 z: " << msg->pose.pose.position.z << std::endl;
    std::cout<<"Received ODOM data: Quaternion orientation (x, y, z, w)"<<std::endl;
    std::cout << "    float64 x: " << msg->pose.pose.orientation.x << std::endl;
    std::cout << "    float64 y: " << msg->pose.pose.orientation.y << std::endl;
    std::cout << "    float64 z: " << msg->pose.pose.orientation.z << std::endl;
    std::cout << "    float64 w: " << msg->pose.pose.orientation.w << std::endl;
    std::cout<<"Received ODOM data: linear (x, y, z)"<<std::endl;
    std::cout << "    float64 x: " << msg->twist.twist.linear.x << std::endl;
    std::cout << "    float64 y: " << msg->twist.twist.linear.y << std::endl;
    std::cout << "    float64 z: " << msg->twist.twist.linear.z << std::endl;
    std::cout<<"Received ODOM data: angular (x, y, z)"<<std::endl;
    std::cout << "    float64 x: " << msg->twist.twist.angular.x << std::endl;
    std::cout << "    float64 y: " << msg->twist.twist.angular.y << std::endl;
    std::cout << "    float64 z: " << msg->twist.twist.angular.z << std::endl;
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "odom_topic");  // 初始化ROS节点
    ros::NodeHandle nh;  // 创建节点句柄

    // 创建订阅器，订阅IMU和里程计主题
    ros::Subscriber odom_sub = nh.subscribe("/odom", 1000, imuCallback);

    ros::spin();  // 循环等待接收ROS消息

    return 0;
}
