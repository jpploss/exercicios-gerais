#include "pessoa.h"
#include <stdio.h>


int main() {
    int qtdPessoas;
    scanf("%d", &qtdPessoas);
    tPessoa pessoas[qtdPessoas];

    for(int i = 0; i < qtdPessoas; i++) {
        pessoas[i] = CriaPessoa();
    }

    AssociaFamiliasGruposPessoas(pessoas);

    for(int i = 0; i < qtdPessoas; i++) {
        ImprimePessoa((pessoas + i));
    }

    return 0;
}