#include "aluno.h"
#include <stdio.h>

tAluno LeAluno() {
    tAluno aluno;
    scanf("%*[^\n]");
    scanf("%*c");
    scanf("%s %d %f%f%f", aluno.nome, &aluno.matricula, &aluno.n1, &aluno.n2, &aluno.n3);
    return aluno;
}

int VerificaAprovacao(tAluno aluno) {
    float media = (aluno.n1 + aluno.n2 + aluno.n3)/3.00;
    if(media >= 7) return 1;
    return 0;
}

int ObtemMatricula(tAluno aluno) {
    return aluno.matricula;
}

int EhMatriculaMenor(tAluno aluno1, tAluno aluno2) {
    if(aluno1.matricula < aluno2.matricula) return 1;
    return 0;
}

void PrintaNome(tAluno aluno) {
    printf("%s\n", aluno.nome);
    return;
}
