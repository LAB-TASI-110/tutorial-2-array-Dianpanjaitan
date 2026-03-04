#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk INT_MAX dan INT_MIN (nilai integer maksimum dan minimum)

int main() {
    int n; // Variabel untuk menyimpan jumlah baris angka
    int num; // Variabel untuk menyimpan setiap bilangan yang diinput
    int min_val = INT_MAX; // Inisialisasi min_val dengan nilai integer terbesar
    int max_val = INT_MIN; // Inisialisasi max_val dengan nilai integer terkecil

    // Menerima input n sebagai jumlah baris angka
    // Tidak ada validasi input untuk n sesuai permintaan
    scanf("%d", &n);

    // Loop untuk menerima n buah bilangan bulat
    for (int i = 0; i < n; i++) {
        scanf("%d", &num); // Menerima bilangan bulat
        
        // Membandingkan dengan nilai terkecil yang sudah ada
        if (num < min_val) {
            min_val = num;
        }
        
        // Membandingkan dengan nilai terbesar yang sudah ada
        if (num > max_val) {
            max_val = num;
        }
    }

    // Menampilkan nilai terkecil pada baris pertama
    printf("%d\n", min_val);
    
    // Menampilkan nilai terbesar pada baris kedua
    printf("%d\n", max_val);

    return 0; // Menandakan program berakhir dengan sukses
}