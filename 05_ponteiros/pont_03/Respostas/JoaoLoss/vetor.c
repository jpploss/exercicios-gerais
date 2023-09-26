#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int* vet, int tam) {
    for(int i = 0; i < tam; i++) {
        scanf("%d", (vet + i));
    }
    return;
}

void OrdeneCrescente(int* vet, int tam) {
    int aux;
    for(int i = 0; i < tam; i++) {
        for(int j = i; j < tam; j++) {
            if(*(vet + i) > *(vet + j)) {
                aux = *(vet + i);
                *(vet + i) = *(vet + j);
                *(vet + j) = aux;
            }
        }
    }
    return;
}

void ImprimeDadosDoVetor(int* vet, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", *(vet + i));
    }
    printf("\n");
    return;
}