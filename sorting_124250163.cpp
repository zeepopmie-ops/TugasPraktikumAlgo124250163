#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk melakukan Bubble Sort (Ascending / A-Z)
void bubbleSort(string array[], int n) {

    // Loop untuk jumlah iterasi pengurutan
    for(int i = 0; i < n - 1; i++) {

        // Loop untuk membandingkan elemen
        for(int j = 0; j < n - i - 1; j++) {

            // Jika elemen sekarang lebih besar dari elemen berikutnya
            if(array[j] > array[j + 1]) {

                // Tukar posisi elemen
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

            }
        }
    }
}


// Fungsi partition untuk Quick Sort (Descending)
int partition(string array[], int low, int high) {

    // Menentukan pivot (elemen terakhir)
    string pivot = array[high];

    // Index elemen yang lebih besar dari pivot
    int i = low - 1;

    // Loop membandingkan elemen
    for(int j = low; j < high; j++) {

        // Jika elemen lebih besar dari pivot (descending)
        if(array[j] > pivot) {

            i++;

            // Tukar posisi elemen
            string temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Tukar pivot ke posisi yang benar
    string temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}


// Fungsi Quick Sort (Descending / Z-A)
void quickSort(string array[], int low, int high) {

    // Jika masih ada elemen untuk diurutkan
    if(low < high) {

        // Menentukan posisi pivot
        int pi = partition(array, low, high);

        // Rekursi bagian kiri
        quickSort(array, low, pi - 1);

        // Rekursi bagian kanan
        quickSort(array, pi + 1, high);
    }
}


// Fungsi untuk menampilkan array
void tampilData(string array[], int n) {

    // Loop menampilkan seluruh nama
    for(int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }
}


// Program utama
int main() {

    // Variabel jumlah mahasiswa
    int n;

    // Input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    // Deklarasi array nama mahasiswa
    string nama[n];

    // Input daftar nama mahasiswa
    for(int i = 0; i < n; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin >> nama[i];
    }

    // Bubble Sort Ascending
    bubbleSort(nama, n);

    // Menampilkan hasil ascending
    cout << "\nData setelah Bubble Sort (Ascending A-Z):\n";
    tampilData(nama, n);

    // Quick Sort Descending
    quickSort(nama, 0, n - 1);

    // Menampilkan hasil descending
    cout << "\nData setelah Quick Sort (Descending Z-A):\n";
    tampilData(nama, n);

    return 0;
}
