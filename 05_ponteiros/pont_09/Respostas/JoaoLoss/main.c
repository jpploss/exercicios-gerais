#include "pessoa.h"
#include <stdio.h>


int main() {
    int qtdPessoas;
    scanf("%d", &qtdPessoas);
    scanf("%*[^\n]");
    scanf("%*c");
    tPessoa pessoas[qtdPessoas];

    for(int i = 0; i < qtdPessoas; i++) {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    // Obs.: vet[i] = *(vet + i), portanto, para ter o endereço do elemento de índice i: &vet[i] ou (vet + i)

    AssociaFamiliasGruposPessoas(pessoas);

    for(int i = 0; i < qtdPessoas; i++) {
        ImprimePessoa((pessoas + i));
    }

    return 0;
}