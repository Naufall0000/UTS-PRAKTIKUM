#include <iostream>

    //fungsi total kecepatan
        void hitungJarak(double* jarak, double* waktu, double* kecepatan, int n){
            for (int i = 0; i < n; i++){
            if (waktu[i] != 0) {
            jarak[i] = kecepatan[i] * (waktu[i] / 60.0); 
            } 
            else {
            jarak[i] = 0; 
            }
        }
    }
    //fungsi hitung rata rata kecepatan
        void hitungRataRataKecepatan(double* kecepatan, int n, double* rataRata){
            double totalKecepatan = 0;
                for (int i = 0; i < n; i++){
                    totalKecepatan += kecepatan[i];
            }
            *rataRata = totalKecepatan / n; 
    }

int main(){

            std::string kotaAsal, kotaTujuan;
            //input kota asal dan tujuan
            std::cout << "masukkan nama kota asal: ";
            std::cin >> kotaAsal;
            std::cout << "Masukkan nama kota tujuan: ";
            std::cin >> kotaTujuan;

        int n;
            std::cout << "Masukkan jumlah kendaraan: ";
            std::cin >> n ;


        std::string* jenisKendaraan = new std::string[n];
        for (int i = 0; i < n; i++){
            std::cout << "masukkan jenis kendaraan " << (i + 1) << ": ";
            std::cin >> jenisKendaraan[i];
        }

        //deklarasi array jarak,waktu, kecepatan
        double* jarak = new double[n];
        double* waktu = new double[n];
        double* kecepatan = new double[n];

        //input kecepatan dan
        for (int i = 0; i < n; i++) {
            std::cout << "Masukkan kecepatan kendaraan" << jenisKendaraan[i] <<   " (dalam km/jam): ";
            std::cin >> kecepatan[i];
            std::cout << "Masukkan waktu yang di tempuh dari " << kotaTujuan << " menggunakan kendaraan " << jenisKendaraan[i] <<  " (dalam menit): ";
            std::cin >> waktu[i];
        }


        hitungJarak(jarak, waktu, kecepatan, n);
            std::cout << "\nJarak kendaraan yang di tempuh dari gianyar ke denpasar adalah: \n";
            for (int i = 0; i < n; i++){
            std::cout << jenisKendaraan[i] << ": " << jarak[i]  << "KM" << std::endl;
        }

        double ratarataKecepatan;
            hitungRataRataKecepatan(kecepatan, n, &ratarataKecepatan);
            std::cout << "rata-rata kecepatan kendaraan selama perjalanan: " <<ratarataKecepatan << "km/jam" << std::endl;

    delete[] jenisKendaraan;
    delete[] waktu;
    delete[] kecepatan;
    delete[] jarak;


    return 0;
}
