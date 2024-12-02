#include <stdio.h>

#define TAMANHO 7

void insertionSort(int arr[]) {
    for (int i = 1; i < TAMANHO; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[TAMANHO] = {64, 34, 25, 12, 22, 11, 90};
    
    insertionSort(arr);
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}