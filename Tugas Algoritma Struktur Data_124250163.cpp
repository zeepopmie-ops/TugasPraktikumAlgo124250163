#include <iostream>     // Library untuk input dan output
#include <string>       // Library untuk tipe data string
using namespace std;


// Struct untuk menyimpan data buku
struct Buku {
    string nama;    // Menyimpan nama buku
    int harga;      // Menyimpan harga buku
};


// 1. Sequential Search TANPA Sentinel
int sequentialTanpaSentinel(Buku data[], int n, string target) {

    int i = 0;  // Variabel indeks

    // Loop selama indeks masih dalam batas array
    while (i < n) {

        // Jika nama buku sama dengan target
        if (data[i].nama == target) {
            return i;  // Kembalikan posisi indeks
        }

        i++;  // Pindah ke indeks berikutnya
    }

    return -1;  // Jika tidak ditemukan
}


// 2. Sequential Search DENGAN Sentinel

int sequentialDenganSentinel(Buku data[], int n, string target) {

    // Menambahkan sentinel di indeks terakhir
    data[n].nama = target;

    int i = 0;

    // Loop sampai menemukan target
    while (data[i].nama != target) {
        i++;
    }

    // Jika indeks masih dalam batas data asli
    if (i < n) {
        return i;  // Data ditemukan
    } else {
        return -1; // Data tidak ditemukan
    }
}

// ========================================
// 3. Binary Search
// Data HARUS dalam kondisi terurut A-Z
// ========================================
int binarySearch(Buku data[], int n, string target) {

    int kiri = 0;          // Batas kiri
    int kanan = n - 1;     // Batas kanan

    // Loop selama masih ada rentang pencarian
    while (kiri <= kanan) {

        int tengah = (kiri + kanan) / 2;  // Hitung indeks tengah

        // Jika data tengah sama dengan target
        if (data[tengah].nama == target) {
            return tengah;  // Ditemukan
        }
        // Jika target lebih besar dari data tengah
        else if (data[tengah].nama < target) {
            kiri = tengah + 1;  // Geser ke kanan
        }
        // Jika target lebih kecil
        else {
            kanan = tengah - 1; // Geser ke kiri
        }
    }

    return -1;  // Jika tidak ditemukan
}


// PROGRAM UTAMA
int main() {

    // Array buku (+1 slot untuk sentinel)
    Buku daftarBuku[6] = {
        {"Algoritma", 85000},
        {"BasisData", 90000},
        {"Jaringan", 75000},
        {"Pemrograman", 95000},
        {"StrukturData", 88000}
    };

    int jumlahBuku = 5;   // Jumlah data asli
    string cari;          // Untuk menyimpan nama buku yang dicari
    int pilihan;          // Untuk memilih metode pencarian

    // Tampilan awal program
    cout << "=== PENCARIAN HARGA BUKU ===" << endl;

    // Input nama buku
    cout << "Masukkan nama buku: ";
    cin >> cari;

    // Menu pilihan metode
    cout << "\nPilih metode pencarian:" << endl;
    cout << "1. Sequential Tanpa Sentinel" << endl;
    cout << "2. Sequential Dengan Sentinel" << endl;
    cout << "3. Binary Search" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    int hasil = -1;  // Menyimpan hasil pencarian

    // Percabangan sesuai pilihan user
    switch (pilihan) {
        case 1:
            hasil = sequentialTanpaSentinel(daftarBuku, jumlahBuku, cari);
            break;
        case 2:
            hasil = sequentialDenganSentinel(daftarBuku, jumlahBuku, cari);
            break;
        case 3:
            hasil = binarySearch(daftarBuku, jumlahBuku, cari);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    // Menampilkan hasil pencarian
    if (hasil != -1) {
        cout << "\nData buku ditemukan!" << endl;
        cout << "Nama  : " << daftarBuku[hasil].nama << endl;
        cout << "Harga : Rp" << daftarBuku[hasil].harga << endl;
    } 
    else {
        cout << "\nBuku tidak ditemukan." << endl;
    }

    return 0;  // Program selesai
}
