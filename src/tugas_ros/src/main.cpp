#include "../include/tugas_ros/header.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "personal_finance_manager");
    ros::NodeHandle nh;

    menghitung manager; 
    int pilihan;

    do {
        ostringstream oss;
        oss << "\nPersonal Finance Manager\n";
        oss << "1. Tambah Transaksi\n";
        oss << "2. Lihat Transaksi\n";
        oss << "3. Perbarui Transaksi\n";
        oss << "4. Hapus Transaksi\n";
        oss << "5. Keluar\n";
        oss << "Pilih opsi: ";
        ROS_INFO_STREAM(oss.str());
        cin >> pilihan;

        if (pilihan == 1) {
            double jumlah;
            string tipe, kategori, tanggal;

            ROS_INFO_STREAM("Masukkan jumlah: ");
            cin >> jumlah;
            ROS_INFO_STREAM("Masukkan tipe (Pemasukan/Pengeluaran): ");
            cin >> tipe;
            ROS_INFO_STREAM("Masukkan kategori: ");
            cin >> kategori;
            ROS_INFO_STREAM("Masukkan tanggal (e.g., 2024-10-25): ");
            cin >> tanggal;

            manager.createtransaksi(jumlah, tipe, kategori, tanggal);
        } else if (pilihan == 2) {
            manager.readtransaksi();
        } else if (pilihan == 3) {
            int id;
            double jumlahBaru;
            string kategoriBaru, tipeBaru, tanggalBaru;

            ROS_INFO_STREAM("Masukkan ID transaksi yang akan diperbarui: ");
            cin >> id;
            ROS_INFO_STREAM("Masukkan jumlah baru: ");
            cin >> jumlahBaru;
            ROS_INFO_STREAM("Masukkan tipe baru: ");
            cin >> tipeBaru;
            ROS_INFO_STREAM("Masukkan kategori baru: ");
            cin >> kategoriBaru;
            ROS_INFO_STREAM("Masukkan tanggal baru: ");
            cin >> tanggalBaru;

            manager.updatetransaksi(id, jumlahBaru, tipeBaru, kategoriBaru, tanggalBaru);
        } else if (pilihan == 4) {
            int id;

            ROS_INFO_STREAM("Masukkan ID transaksi yang akan dihapus: ");
            cin >> id;

            manager.deletetransaksi(id);
        } else if (pilihan == 5) {
            ROS_INFO_STREAM("Keluar dari program.");
        } else {
            ROS_INFO_STREAM("Pilihan tidak valid. Coba lagi.");
        }
    } while (pilihan != 5);

    return 0;
}