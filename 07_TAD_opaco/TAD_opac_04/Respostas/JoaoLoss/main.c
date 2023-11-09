#include <stdio.h>
#include "aluno.h"

int main() {
    int qtdAlunos;
    scanf("%d", &qtdAlunos);

    tAluno* alunos[qtdAlunos];

    for(int i = 0; i < qtdAlunos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    tAluno* alunoAux;
    for(int i = 0; i < qtdAlunos; i++) {
        for(int j = i; j < qtdAlunos; j++) {
            if(ComparaMatricula(alunos[j], alunos[i]) == -1) {
                alunoAux = alunos[j];
                alunos[j] = alunos[i];
                alunos[i] = alunoAux;
            }
        }
    }

    for(int i = 0; i < qtdAlunos; i++) {
        if(VerificaAprovacao(alunos[i])) ImprimeAluno(alunos[i]);
        ApagaAluno(alunos[i]);
    }



    return 0;
}