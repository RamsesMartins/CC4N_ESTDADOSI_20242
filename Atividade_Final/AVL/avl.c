#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
    int altura;
};

int altura(struct No* No) {
    if (No == NULL) return 0;
    return No->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

int fatorBalanceamento(struct No* No) {
    if (No == NULL) return 0;
    return altura(No->esquerda) - altura(No->direita);
}

struct No* rotacaoDireita(struct No* y) {
    struct No* x = y->esquerda;
    struct No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

struct No* rotacaoEsquerda(struct No* x) {
    struct No* y = x->direita;
    struct No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    else
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    int balanceamento = fatorBalanceamento(raiz);

    if (balanceamento > 1 && valor < raiz->esquerda->valor)
        return rotacaoDireita(raiz);

    if (balanceamento < -1 && valor > raiz->direita->valor)
        return rotacaoEsquerda(raiz);

    if (balanceamento > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

struct No* buscar(struct No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);

    return buscar(raiz->direita, valor);
}

void imprimirEmOrdem(struct No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    struct No* raiz = NULL;
    
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Arvore em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    int valorBusca = 40;
    struct No* resultado = buscar(raiz, valorBusca);
    
    if (resultado != NULL) {
        printf("Valor %d encontrado na arvore!\n", valorBusca);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valorBusca);
    }

    return 0;
}