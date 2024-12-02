#include <stdio.h>

void shellSort(int vetor[], int tamanho) {
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < tamanho; i++) {
            int elementoAtual = vetor[i];
            int j;
            
            for (j = i; j >= intervalo && vetor[j - intervalo] > elementoAtual; j -= intervalo) {
                vetor[j] = vetor[j - intervalo];
            }
            
            vetor[j] = elementoAtual;
        }
    }
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    shellSort(vetor, tamanho);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}