
#include <iostream>


//fungsi menghitung kecepatan
            void hitungKecepatanKendaraan(double* jarak, double* waktu, double* kecepatan, int n){
            for (int i = 0; i < n; i++){
            if (waktu[i] != 0) {
            kecepatan[i] = (jarak[i] ) / (waktu[i] / 60.0);  
            } 
            else {
            kecepatan[i] = 0; 
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

// Fungsi menghitung kecepatan tertinggi
void hitungKecepatanTertinggi(double* kecepatan, int n, double* max) {
    *max = kecepatan[0]; // Asumsikan kecepatan pertama adalah yang tertinggi
    for (int i = 1; i < n; i++) {
        if (kecepatan[i] > *max) {
            *max = kecepatan[i]; // Update jika ditemukan kecepatan lebih tinggi
        }
    }
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
            std::cout << "Masukkan waktu yang di tempuh dari " << kotaTujuan << " menggunakan kendaraan " << jenisKendaraan[i] <<  " (dalam Menit): ";
            std::cin >> waktu[i];
        }

//memanggil fungsi hitungKecepatanKendaraan
        hitungKecepatanKendaraan(jarak, waktu, kecepatan, n);
            std::cout << "Kecepatan kendaraan yang di tempuh dari " << kotaAsal << " menuju " << kotaTujuan << " adalah: " << std::endl ;
            for (int i = 0; i < n; i++){
            std::cout << jenisKendaraan[i] << ": " << kecepatan[i]  << "km/jam" << std::endl;
        }

//memanggil fungsi hitungRataRataKecepatan
        double ratarataKecepatan;
            hitungRataRataKecepatan(kecepatan, n, &ratarataKecepatan);
            std::cout << "rata-rata kecepatan kendaraan selama perjalanan: " <<ratarataKecepatan << "km/jam" << std::endl;


// Memanggil fungsi hitungKecepatanTertinggi
    double kecepatanTertinggi;
    hitungKecepatanTertinggi(kecepatan, n, &kecepatanTertinggi);
    std::cout << "Kecepatan tertinggi adalah: " << kecepatanTertinggi << " km/jam" << std::endl;


//menghapus array dinamis supaya tidak crash
    delete[] jenisKendaraan;
    delete[] waktu;
    delete[] kecepatan;
    delete[] jarak;


    return 0;
}