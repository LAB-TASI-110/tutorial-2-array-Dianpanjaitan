#include <stdio.h>    
#include <limits.h>   
#include <stdlib.h>   
#include <float.h>    

int processInputNumbers(int* min_val_ptr, int* max_val_ptr, double* lowest_avg_ptr, double* highest_avg_ptr) {
    int n; 
    scanf("%d", &n); 
   
    *min_val_ptr = INT_MAX;
    *max_val_ptr = INT_MIN;
    *lowest_avg_ptr = DBL_MAX;   
    *highest_avg_ptr = DBL_MIN;  

    
    if (n <= 0) {
        return n;
    }

    
    int* numbers = (int*) malloc(n * sizeof(int));
    if (numbers == NULL) {
        
        fprintf(stderr, "Gagal mengalokasikan memori!\n");
        exit(EXIT_FAILURE);
    }

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]); 
        
        
        if (numbers[i] < *min_val_ptr) {
            *min_val_ptr = numbers[i];
        }
        
       
        if (numbers[i] > *max_val_ptr) {
            *max_val_ptr = numbers[i];
        }
    }

    
    if (n >= 2) {
        for (int i = 0; i < n - 1; i++) {
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            
            
            if (current_avg < *lowest_avg_ptr) {
                *lowest_avg_ptr = current_avg;
            }
            
            
            if (current_avg > *highest_avg_ptr) {
                *highest_avg_ptr = current_avg;
            }
        }
    }
    
    free(numbers);
    
    return n; 
}


void displayResults(int n_val, int min_val, int max_val, double lowest_avg, double highest_avg) {
    
    if (n_val > 0) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
    }
    
    
    if (n_val >= 2 && lowest_avg != DBL_MAX) {
        printf("%.2f\n", lowest_avg); 
    }

    
    if (n_val >= 2 && highest_avg != DBL_MIN) {
        printf("%.2f\n", highest_avg); 
    }
}

int main() {
    int min_val_result;
    int max_val_result;
    double lowest_avg_result;
    double highest_avg_result; 
    int n_input; 

    
    n_input = processInputNumbers(&min_val_result, &max_val_result, &lowest_avg_result, &highest_avg_result);

    displayResults(n_input, min_val_result, max_val_result, lowest_avg_result, highest_avg_result);

    return 0; 
}