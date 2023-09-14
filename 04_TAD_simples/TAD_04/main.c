#include "aluno.h"
#include <stdio.h>

int main() {
    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    tAluno alunos[qtdAlunos];

    tAluno alunoAtual, auxiliaOrdenacao;
    for(int i = 0; i < qtdAlunos; i++) { // le os alunos
        alunoAtual = LeAluno();
        alunos[i] = alunoAtual;
    }

    for(int i = 0; i < qtdAlunos; i++) {
        for(int j = i + 1; j < qtdAlunos; j++) {
            if(EhMatriculaMenor(alunos[j], alunos[i])) {
                auxiliaOrdenacao = alunos[j];
                alunos[j] = alunos[i];
                alunos[i] = auxiliaOrdenacao;
            }
        }
    }

    for(int i = 0; i < qtdAlunos; i++) {
        if(VerificaAprovacao(alunos[i])) PrintaNome(alunos[i]);
    }

    return 0;
}