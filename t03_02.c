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

// FUNGSI BARU: Fungsi untuk menemukan rata-rata terendah dari dua nilai berturut-turut
double find_lowest_average_of_consecutive_pairs(const int* arr, int n) {
    // Jika jumlah elemen kurang dari 2, tidak ada pasangan berturut-turut yang bisa dibentuk.
    // Mengembalikan 0.0 sebagai nilai default.
    if (n < 2) {
        return 0.0;
    }

    // Inisialisasi nilai rata-rata terendah dengan rata-rata pasangan pertama
    double min_avg = (double)(arr[0] + arr[1]) / 2.0;

    // Iterasi melalui sisa pasangan
    for (int i = 1; i < n - 1; ++i) {
        double current_avg = (double)(arr[i] + arr[i+1]) / 2.0;
        if (current_avg < min_avg) {
            min_avg = current_avg; // Perbarui min_avg jika ditemukan yang lebih rendah
        }
    }
    return min_avg;
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
    
    // Memanggil fungsi baru untuk mencari rata-rata terendah dari pasangan berturut-turut
    double lowest_consecutive_avg_result = find_lowest_average_of_consecutive_pairs(numbers, n);

    // Mencetak nilai minimum, maksimum, dan rata-rata terendah sesuai spesifikasi keluaran
    printf("%d\n", min_result);
    printf("%d\n", max_result);
    printf("%.2f\n", lowest_consecutive_avg_result); // Mencetak dengan 2 digit presisi

    // Membebaskan memori yang telah dialokasikan secara dinamis untuk mencegah memory leak
    free(numbers);
    numbers = NULL; // Praktik baik untuk menghindari dangling pointer

    return 0; // Mengindikasikan program berjalan sukses
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
    
    // Memanggil fungsi baru untuk mencari rata-rata terendah dari pasangan berturut-turut
    double lowest_consecutive_avg_result = find_lowest_average_of_consecutive_pairs(numbers, n);

    // Mencetak nilai minimum, maksimum, dan rata-rata terendah sesuai spesifikasi keluaran
    printf("%d\n", min_result);
    printf("%d\n", max_result);
    printf("%.2f\n", lowest_consecutive_avg_result); // Mencetak dengan 2 digit presisi

    // Membebaskan memori yang telah dialokasikan secara dinamis untuk mencegah memory leak
    free(numbers);
    numbers = NULL; // Praktik baik untuk menghindari dangling pointer

    return 0; // Mengindikasikan program berjalan sukses
}