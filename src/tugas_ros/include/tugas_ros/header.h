#ifndef MENGHITUNG_H
#define MENGHITUNG_H

#include <ros/ros.h>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

class transaksi {
    private:
    int id;
    double jumlahTransaksi;
    string tipe, kategori, tanggal;

    public:
    transaksi() : id(0), jumlahTransaksi(0.0), tipe(""), kategori(""), tanggal("") {}
    transaksi(int id, double jumlahTransaksi, string tipe, string kategori, string tanggal)
        : id(id), jumlahTransaksi(jumlahTransaksi), tipe(tipe), kategori(kategori), tanggal(tanggal) {}

    int getid() { return id; }
    double getjumlahTransaksi() { return jumlahTransaksi; }
    string gettipe() { return tipe; }
    string getkategori() { return kategori; }
    string gettanggal() { return tanggal; }

    void setjumlahTransaksi(double jumlahtransaksi) { jumlahTransaksi = jumlahtransaksi; }
    void setkategori(string Kategori) { kategori = Kategori; }
    void settanggal(string Tanggal) { tanggal = Tanggal; }

    void display() {
        ostringstream oss;
        oss << "ID: " << id << ", Tipe Transaksi: " << tipe << ", Amount: " << jumlahTransaksi
            << ", Kategori: " << kategori << ", Tanggal Transaksi: " << tanggal;
        ROS_INFO_STREAM(oss.str());
    }
};

class menghitung {
    private:
    unordered_map<int, transaksi> Transaksi;
    int nextid = 1;

    public:
    void createtransaksi(double jumlahtransaksi, string tipe, string kategori, string tanggal) {
        transaksi newtransaksi(nextid, jumlahtransaksi, tipe, kategori, tanggal);
        Transaksi[nextid++] = newtransaksi;
        ROS_INFO_STREAM("Transaksi Berhasil");
    }

    void readtransaksi() {
        for (auto itr = Transaksi.begin(); itr != Transaksi.end(); itr++) {
            itr->second.display();
        }
    }

    void updatetransaksi(int id, double transaksi, string tipe, string kategori, string tanggal) {
        if (Transaksi.find(id) != Transaksi.end()) {
            Transaksi[id].setjumlahTransaksi(transaksi);
            Transaksi[id].setkategori(kategori);
            Transaksi[id].settanggal(tanggal);
            ROS_INFO_STREAM("data berhasil diupdate");
        } else {
            ROS_INFO_STREAM("data tidak ditemukan");
        }
    }

    void deletetransaksi(int id) {
        if (Transaksi.erase(id)) {
            ROS_INFO_STREAM("transaksi berhasil dihapus");
        } else {
            ROS_INFO_STREAM("transaksi dengan id " << id << " tidak ditemukan");
        }
    }
};

#endif // MENGHITUNG_H