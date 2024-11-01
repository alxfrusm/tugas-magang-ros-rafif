#include "../include/tugas_ros/header.h"
#include <ros/ros.h>
#include <std_msgs/String.h>

void transaksiCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO_STREAM("Transaksi diterima: " << msg->data);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "personal_finance_listener");
    ros::NodeHandle nh;

    ros::Subscriber transaksi_sub = nh.subscribe("transaksi", 1000, transaksiCallback);
    ros::spin();

    return 0;
}
