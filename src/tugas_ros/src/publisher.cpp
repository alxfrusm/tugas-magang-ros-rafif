#include "../include/tugas_ros/header.h"
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <iostream>

int saldo = 0; // Variabel global saldo

int main(int argc, char** argv) {
    ros::init(argc, argv, "personal_finance_publisher");
    ros::NodeHandle nh;

    ros::Publisher transaksi_pub = nh.advertise<std_msgs::String>("transaksi", 1000);

    while (ros::ok()) {
        std_msgs::String msg;
        std::ostringstream oss;
        
        double jumlah;
        std::string tipe, kategori, tanggal;

        std::cout << "Masukkan jumlah: ";
        std::cin >> jumlah;
        std::cout << "Masukkan tipe (Pemasukan/Pengeluaran): ";
        std::cin >> tipe;
        std::cout << "Masukkan kategori: ";
        std::cin >> kategori;
        std::cout << "Masukkan tanggal (e.g., 2024-10-25): ";
        std::cin >> tanggal;

        oss << "Jumlah: " << jumlah << ", Tipe: " << tipe << ", Kategori: " << kategori << ", Tanggal: " << tanggal;
        msg.data = oss.str();

        transaksi_pub.publish(msg);
        ROS_INFO_STREAM("Transaksi dipublikasikan: " << msg.data);

        ros::spinOnce();
    }

    return 0;
}
