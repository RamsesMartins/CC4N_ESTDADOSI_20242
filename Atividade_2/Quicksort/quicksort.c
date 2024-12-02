#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int organizarVetor(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int posicaoPivo = inicio - 1;

    for (int i = inicio; i < fim; i++) {
        if (vetor[i] <= pivo) {
            posicaoPivo++;
            trocar(&vetor[posicaoPivo], &vetor[i]);
        }
    }

    trocar(&vetor[posicaoPivo + 1], &vetor[fim]);
    return posicaoPivo + 1;
}

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = organizarVetor(vetor, inicio, fim);
        
        quickSort(vetor, inicio, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, fim);
    }
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    quickSort(vetor, 0, tamanho - 1);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}