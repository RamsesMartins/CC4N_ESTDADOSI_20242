#include <stdio.h>

#define TAMANHO 7
void selectionSort(int arr[]) {
    for (int i = 0; i < TAMANHO - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < TAMANHO; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[TAMANHO] = {64, 34, 25, 12, 22, 11, 90};
    
    selectionSort(arr);
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}