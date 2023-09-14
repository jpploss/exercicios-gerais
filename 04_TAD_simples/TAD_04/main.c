#include "aluno.h"
#include <stdio.h>

int main() {
    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    tAluno alunos[qtdAlunos];

    tAluno alunoAtual, auxiliaOrdenacao;
    for(int i = 0; i < qtdAlunos; i++) { // le os alunos
        alunoAtual = LeAluno();

        if(i == 0) {
            alunos[i] = alunoAtual;
            continue;
        }

        for(int j = 0; j < i; j++) { // verifica se algum aluno ja lido tem matricula menor
            if(EhMatriculaMenor(alunoAtual, alunos[j])) { // se a matricula for menor, troca de posicao
                auxiliaOrdenacao = alunos[j];
                alunos[j] = alunoAtual;
                alunos[i] = auxiliaOrdenacao;
                break;
            } else if(j == i - 1) { // se o ultimo aluno anterior nn tiver matricula menor: coloca o alunoAtual na ultima posicao do vetor 
                alunos[i] = alunoAtual;
                break;
            }

        }
    }

    for(int i = 0; i < qtdAlunos; i++) {
        PrintaNome(alunos[i]);
    }

    return 0;
}