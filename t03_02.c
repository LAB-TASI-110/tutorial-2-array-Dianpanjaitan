#include <stdio.h>
#include <limits.h>

int main() {
    int n, num, prev;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    float min_avg = 1e9; // Inisialisasi dengan nilai sangat besar

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &num) != 1) break;

        
        // Update min & max global
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;

        // Hitung rata-rata berurutan mulai dari angka kedua
        if (i > 0) {
            float current_avg = (float)(prev + num) / 2.0;
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
        }
        prev = num;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", min_avg);

    return 0;
}