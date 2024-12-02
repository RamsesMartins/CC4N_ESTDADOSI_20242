#include <stdio.h>

#define TAMANHO 7

void bubbleSort(int arr[]) {
    for (int i = 0; i < TAMANHO - 1; i++) {
        for (int j = 0; j < TAMANHO - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[TAMANHO] = {64, 34, 25, 12, 22, 11, 90};
    
    bubbleSort(arr);
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}