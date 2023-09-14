#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct {
    char nome[101];
    int matricula;
    float n1, n2, n3;
} tAluno;

tAluno LeAluno();

int VerificaAprovacao(tAluno aluno);

int ObtemMatricula(tAluno aluno);

int EhMatriculaMenor(tAluno aluno1, tAluno aluno2);

void PrintaNome(tAluno aluno);

#endif