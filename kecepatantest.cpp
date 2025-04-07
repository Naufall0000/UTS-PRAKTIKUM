#include <iostream>

    //fungsi total kecepatan
    void hitungKecepatan(double* jarak, double* waktu, double* kecepatan, int n){
        for (int i = 0; i < n; i++){
            if (waktu[i] != 0) {
                kecepatan[i] = jarak[i] / waktu[i];
            } 
            else {
                kecepatan[i] = 0; //  'kecepatan[i] = 0; berfungsi untuk menyimpan data hasil sementara dari jarak[i] dibagi waktu[i]
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

    int n;
    std::cout << "Masukkan jumlah kendaraan: ";
    std::cin >> n ;

    //deklarasi array jarak,waktu, kecepatan
    double* jarak = new double[n];
    double* waktu = new double[n];
    double* kecepatan = new double[n];

    //input
    for (int i = 0; i < n; i++) {
        std::cout << "Masukkan jarak yang di tempuh kendaraan" << (i + 1) << "(dalam km): ";
        std::cin >> jarak[i];
        std::cout << "Masukkan waktu yang di tempuh kendaraan" << (i + 1) << "(dalam jam): ";
        std::cin >> waktu[i];
    }


    hitungKecepatan(jarak, waktu, kecepatan, n);

    std::cout << "\nKecepatan kendaraan: \n";
    for (int i = 0; i < n; i++){
        std::cout << "Kendaraan" << (i + 1) << ": " << kecepatan[i]  << "km/jam" << std::endl;
    }

    double ratarataKecepatan;
     hitungRataRataKecepatan(kecepatan, n, &ratarataKecepatan);
    std::cout << "rata-rata kecepatan kendaraan: " <<ratarataKecepatan << "km/jam" << std::endl;




    return 0;
}


//https://www.blackbox.ai/chat/JlnwtT


//double hitungRataRataKecepatan(double* kecepatan, int n){
    //double totalKecepatan = 0;
   // for (int i = 0; i < n; i++){
       // totalKecepatan += kecepatan[i];
    //}
    //return totalKecepatan / n; 
//}