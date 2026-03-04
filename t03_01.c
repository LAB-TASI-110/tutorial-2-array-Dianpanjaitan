#include <stdio.h>  // Untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Untuk alokasi memori dinamis (malloc dan free)

// Fungsi untuk membaca jumlah bilangan (n) yang akan dimasukkan
int read_n_count() {
    int n;
    scanf("%d", &n); // Membaca nilai n dari input
    return n;
}

// Fungsi untuk membaca n bilangan bulat dan menyimpannya ke dalam array
void read_numbers_into_array(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]); // Membaca setiap bilangan dan menyimpannya ke array
    }
}

// Fungsi untuk menemukan nilai minimum dalam sebuah array bilangan bulat
int find_min_value(const int* arr, int n) {
    // Menangani kasus jika array kosong, meskipun soal menyiratkan n > 0
    if (n <= 0) {
        return 0; // Nilai default atau penanganan error jika tidak ada elemen
    }
    int min_val = arr[0]; // Inisialisasi min_val dengan elemen pertama
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i]; // Update min_val jika ditemukan nilai yang lebih kecil
        }
    }
    return min_val;
}

// Fungsi untuk menemukan nilai maksimum dalam sebuah array bilangan bulat
int find_max_value(const int* arr, int n) {
    // Menangani kasus jika array kosong, meskipun soal menyiratkan n > 0
    if (n <= 0) {
        return 0; // Nilai default atau penanganan error jika tidak ada elemen
    }
    int max_val = arr[0]; // Inisialisasi max_val dengan elemen pertama
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i]; // Update max_val jika ditemukan nilai yang lebih besar
        }
    }
    return max_val;
}

// Fungsi utama program
int main() {
    // Membaca jumlah baris masukan berikutnya (n)
    int n = read_n_count();

    // Mengalokasikan memori secara dinamis untuk menyimpan n bilangan bulat
    // Ini penting karena n tidak diketahui pada saat kompilasi
    int* numbers = (int*)malloc(n * sizeof(int));
    
    // Penanganan error jika alokasi memori gagal
    if (numbers == NULL) {
        fprintf(stderr, "Error: Alokasi memori gagal.\n");
        return 1; // Mengembalikan kode error
    }

    // Membaca n bilangan bulat ke dalam array yang dialokasikan
    read_numbers_into_array(numbers, n);

    // Mencari nilai minimum dan maksimum menggunakan fungsi-fungsi yang telah dibuat
    int min_result = find_min_value(numbers, n);
    int max_result = find_max_value(numbers, n);

    // Mencetak nilai minimum dan maksimum sesuai spesifikasi keluaran
    printf("%d\n", min_result);
    printf("%d\n", max_result);

    // Membebaskan memori yang telah dialokasikan secara dinamis untuk mencegah memory leak
    free(numbers);
    numbers = NULL; // Praktik baik untuk menghindari dangling pointer

    return 0; // Mengindikasikan program berjalan sukses
}