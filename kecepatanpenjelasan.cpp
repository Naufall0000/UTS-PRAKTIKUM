#include <iostream>
// supaya perangkat bisa membaca code dan menjalankannya



//fungsi adalah blok kode yang membuata tugas tertentu dan bisa dipanggil kapan saja

    //fungsi menghitung total kecepatan
            //Fungsi 'void' digunakan untuk mendeklarasi fungsi yang tidak mengembalikan nilai.
            //'jarak, waktu'adalah pointer ke array yang berisi nilai yang kita input'
            // 'kecepatan' adalah pointer ke array yang berisi hasil perhitungan kecepatan 
            //dan sebuah integer 'n' yang menunjukkan jumlah kendaraan
            void hitungKecepatanKendaraan(double* jarak, double* waktu, double* kecepatan, int n){
            for (int i = 0; i < n; i++) // jika i adalah 0 dan i kurang ari n maka loop akan terus berjalan, dan nilai i akan bertambah 1
            {
            if (waktu[i] != 0) // 'if' statement berfungsi untuk memeriksa waktu pada indeks 'i' tidak sama dengan nol (UNTUK MENCEGAH PEMBAGIAN DENGAN NOL) Yang akan menyebabkan kesalahan runtime // JIKA WAKTU[i] sama dengan nol, maka perhitungan kecepatan untuk indeks tidak akan dilakukan
            {
            kecepatan[i] = (jarak[i] ) / (waktu[i] / 60.0); // menghitung kecepatan
            } 
            else {
            kecepatan[i] = 0; // jika waktu yang diinput 0 maka kecepatan pada indeks 'i' diatur menjadi 0
            }
        }
    }



    
    //fungsi hitung rata rata kecepatan
            void hitungRataRataKecepatan(double* kecepatan, int n, double* rataRata) 
            //double* kecepatan berfungsi untuk memanggil hasil kecepatan dari dari fungsi sebelumnya/ berisi nilai kecepatan dari setiap kendaraan.
            // int n = banyak nilai kecepatan yang akan diproses
            // double* rata rata deklarasi untuk menyimpan hasil rata rata kecepatan
            {
            double totalKecepatan = 0; // variabel ini akan digunakan untuk menyimpan jumlah total dari semua nilai kecepatan yang ada dalam array
            for (int i = 0; i < n; i++) // loop yang akan berjalan dari 0 hingga 'n-1' dimana 'n' adalah jumlah elemen dalam array 'kecepatan' 
            {
            totalKecepatan += kecepatan[i]; // nilai kecepatan[i] ditambahkan ke 'totalKecepatan' dengan cara ini loop akan selesai, 'totalKecepatan' akan berisi jumlah dari semua nilai kecepatan dalam array
            }
            *rataRata = totalKecepatan / n;  //menghitung rata rata
            }

int main(){
//titik awal program


            std::string kotaAsal, kotaTujuan; // dua variabel yang dideklarasikan untuk menyimpan nama kota asal dan kota tujuan yang akan di input
            std::cout << "Masukkan nama kota asal: ";
            std::cin >> kotaAsal;
            std::cout << "Masukkan nama kota tujuan: ";
            std::cin >> kotaTujuan;

        int n; // 'n' menyimpan jumlah kendaraan yang akan di input
            std::cout << "Masukkan jumlah kendaraan: ";
            std::cin >> n ;


        std::string* jenisKendaraan = new std::string[n]; // pointer yang akan menunjuk array ke objek bertipe 'std::string' 
        //jenisKendaraan adalah nama variabel pointer yang akan menyimpan alamat dari array 'std::string' yang dialokasikan secara diamis
        //new std::string[n]: operator 'new' digunakan untuk melakukan alokasi memori secara dinamis, kita mengalokasikan memori untuk sebuah array yang berisi 'n' elemen bertipe 'std::string', nilai n ditentukan dari input
        for (int i = 0; i < n; i++) // loop 'for' digunakan untuk mengurangi proses input sebanyak 'n' kali. Variabel 'i' diinisialisasi dengan 0 dan akan bertambah banyak satu setiap iterasi hingga mencapai 'n'
        {
            std::cout << "Masukkan jenis kendaraan " << (i + 1) << ": ";
            std::cin >> jenisKendaraan[i];
        }
        //new std::string[n] mengalokasi n pada jumlah kendaraan yang sudah di input dan jenis kendaraan akan menyesuaikan ke jumlah kendaraan yang sudah disimpan ke 'n' 

        double* jarak = new double[n];
        double* waktu = new double[n];
        double* kecepatan = new double[n];
        //jarak waktu kecepatan akan menyesuaikan nilai n(jumlah kendaraan)

        //input
        for (int i = 0; i < n; i++) {
            std::cout << "Masukkan jarak kendaraan yang di tempuh dari " << kotaAsal << " menggunakan kendaraan " << jenisKendaraan[i] <<   " (dalam KM): ";
            std::cin >> jarak[i];
            std::cout << "Masukkan waktu yang di tempuh dari " << kotaTujuan << " menggunakan kendaraan " << jenisKendaraan[i] <<  " (dalam menit): ";
            std::cin >> waktu[i];
        }


        hitungKecepatanKendaraan(jarak, waktu, kecepatan, n);
        //memanggil fungsi hitungKecepatanKendaraan, 
        //(jarak adalah array yang berisi nilai jarak ditempuh kenderaan)
        //(waktu adalah array yang berisi nilai waktu yang ditempuh)
        //(Kecepatan adalah array yang akan diisi hasil perhitungan)
            std::cout << "Kecepatan kendaraan yang di tempuh dari " << kotaAsal << " menuju " << kotaTujuan << " adalah: " << std::endl;
            for (int i = 0; i < n; i++){
            std::cout << jenisKendaraan[i] << ": " << kecepatan[i]  << "km/jam" << std::endl;
        }

        double ratarataKecepatan;
            hitungRataRataKecepatan(kecepatan, n, &ratarataKecepatan);
            //memanggil fungsi hitungRataKecepatan
            //(kecepatan)
            std::cout << "rata-rata kecepatan kendaraan selama perjalanan: " <<ratarataKecepatan << "km/jam" << std::endl;


//menghapus array dinamis karena kita menggunakan new double saat mendeklarasi array
    delete[] jenisKendaraan;
    delete[] waktu;
    delete[] kecepatan;
    delete[] jarak;


    return 0;
}

