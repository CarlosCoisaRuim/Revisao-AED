#include <stdio.h>
#include <stdlib.h>

void mergesort(int array[], int tamanho);
void merge(int array[], int esquerda[], int tamanho_esquerda, int direita[], int tamanho_direita);

int main() {
    int array[] = {1, 74, 48, 1000000000, 2, 0, 5, 1};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    mergesort(array, tamanho);

    printf("Array ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void mergesort(int array[], int tamanho) {
    if (tamanho <= 1) {
        return;
    }

    int meio = tamanho / 2;
    int *esquerda = (int *)malloc(meio * sizeof(int));
    int *direita = (int *)malloc((tamanho - meio) * sizeof(int));

    for (int i = 0; i < meio; i++) {
        esquerda[i] = array[i];
    }
    for (int i = meio; i < tamanho; i++) {
        direita[i - meio] = array[i];
    }

    mergesort(esquerda, meio);
    mergesort(direita, tamanho - meio);
    merge(array, esquerda, meio, direita, tamanho - meio);

    free(esquerda);
    free(direita);
}

void merge(int array[], int esquerda[], int tamanho_esquerda, int direita[], int tamanho_direita) {
    int i = 0, j = 0, k = 0;

    while (i < tamanho_esquerda && j < tamanho_direita) {
        if (esquerda[i] < direita[j]) {
            array[k++] = esquerda[i++];
        } else {
            array[k++] = direita[j++];
        }
    }

    while (i < tamanho_esquerda) {
        array[k++] = esquerda[i++];
    }

    while (j < tamanho_direita) {
        array[k++] = direita[j++];
    }
}