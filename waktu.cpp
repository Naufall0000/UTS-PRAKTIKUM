#include <iostream>
#include <string>


//fungsi menghitung kecepatan
            void hitungKecepatanKendaraan(double* jarak, double* waktu, double* kecepatan, int n){
            for (int i = 0; i < n; i++){
            if (kecepatan[i] != 0) {
            waktu[i] = (jarak[i] ) / (kecepatan[i]);
            } 
            else {
            waktu[i] = 0; 
            }
        }
    }
//fungsi menghitung rata-rata kecepatan
            void hitungRataRataKecepatan(double* kecepatan, int n, double* rataRata){
            double totalKecepatan = 0;
            for (int i = 0; i < n; i++){
            totalKecepatan += kecepatan[i];
            }
            *rataRata = totalKecepatan / n; 
    }

int main(){

//input kota asal dan kota tujuan
            std::string kotaAsal, kotaTujuan;
            std::cout << "Masukkan nama kota asal: ";
            std::cin >> kotaAsal;
            std::cout << "Masukkan nama kota tujuan: ";
            std::cin >> kotaTujuan;

//input jumlah kendaraan
        int n;
            std::cout << "Masukkan jumlah kendaraan: ";
            std::cin >> n ;

//input jenis kendaraan dan mengalokasi n
        std::string* jenisKendaraan = new std::string[n];
        for (int i = 0; i < n; i++){
            std::cout << "masukkan jenis kendaraan " << (i + 1) << ": ";
            std::cin >> jenisKendaraan[i];
        }

//mengalokasikan 'n' ke jarak waktu kecepatan akan menyesuaikan nilai n
        double* jarak = new double[n];
        double* waktu = new double[n];
        double* kecepatan = new double[n];
        
//input jarak dan waktu
        for (int i = 0; i < n; i++) {
            std::cout << "Masukkan jarak kendaraan yang di tempuh dari " << kotaAsal << " menggunakan kendaraan " << jenisKendaraan[i] <<   " (dalam KM): ";
            std::cin >> jarak[i];
            std::cout << "Masukkan kecepatan yang di tempuh dari " << kotaTujuan << " menggunakan kendaraan " << jenisKendaraan[i] <<  " (dalam Menit): ";
            std::cin >> waktu[i];
        }

//memanggil fungsi hitungKecepatanKendaraan
        hitungKecepatanKendaraan(jarak, waktu, kecepatan, n);
            std::cout << "Kecepatan kendaraan yang di tempuh dari " << kotaAsal << " menuju " << kotaTujuan << " adalah: " << std::endl ;
            for (int i = 0; i < n; i++){
            std::cout << jenisKendaraan[i] << ": " << waktu[i]  << "jam" << std::endl;
        }

//memanggil fungsi hitungRataRataKecepatan
        double ratarataKecepatan;
            hitungRataRataKecepatan(kecepatan, n, &ratarataKecepatan);
            std::cout << "rata-rata kecepatan kendaraan selama perjalanan: " <<ratarataKecepatan << "km/jam" << std::endl;


//menghapus array dinamis supaya tidak crash
    delete[] jenisKendaraan;
    delete[] waktu;
    delete[] kecepatan;
    delete[] jarak;


    return 0;
}