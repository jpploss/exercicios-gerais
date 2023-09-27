#include "utils.h"
#include <stdio.h>

void EncontraMaiorMenorMedia(int *numeros, int tamanho, int *maior, int *menor, float *media) {
    int soma = 0;
    *menor = numeros[0];
    *maior = *menor;
    soma = *menor;

    for(int i = 1; i < tamanho; i++) {
        if(numeros[i] < *menor) *menor = numeros[i];
        else if(numeros[i] > *maior) *maior = numeros[i];
        soma += numeros[i];
    }
    *media = soma/(float)tamanho;

    return;
}

void LeNumeros(int *numeros, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", (numeros + i));
    }
    return;
}