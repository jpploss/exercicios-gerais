#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>

int main() {
    int qtd;
    scanf("%d", &qtd);

    tAluno** alunos = (tAluno**) malloc(sizeof(tAluno*) * qtd); // vetor de ponteiros para tAluno de tamanho qtd

    if(alunos == NULL) {
        printf("Problemas na alocação de memória para o vetor de ponteiros para alunos.\n");
        exit(1);
    }

    for(int i = 0; i < qtd; i++) {
        *(alunos + i) = CriaAluno();
        LeAluno(*(alunos + i));
    }

    tAluno* aux;
    for(int i = 0; i < qtd; i++) {
        for(int j = i + 1; j < qtd; j++) {
            if(ComparaMatricula(*(alunos + i), *(alunos + j)) == 1) {
                aux = *(alunos + i);
                *(alunos + i) = *(alunos + j);
                *(alunos + j) = aux;
            }
        }
    }

    for(int i = 0; i < qtd; i++) {
        if(VerificaAprovacao(*(alunos + i))) {
            ImprimeAluno(*(alunos + i));
            printf("\n");
        }
        ApagaAluno(*(alunos + i));
    }

    free(alunos);

    return 0;
}