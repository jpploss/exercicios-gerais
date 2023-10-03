#include "vetor.h"
#include <stdio.h>

int Soma(int x, int y) {
    return x + y;
}

int Multiplica(int x, int y) {
    return x * y;
}

int main() {
    Vetor vet;
    LeVetor(&vet);
    printf("Soma: %d\nProduto: %d\n", AplicarOperacaoVetor(&vet, Soma), AplicarOperacaoVetor(&vet, Multiplica));

    return 0;
}