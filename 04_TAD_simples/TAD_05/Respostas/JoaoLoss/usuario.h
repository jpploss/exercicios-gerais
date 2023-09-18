#ifndef _USUARIO_H
#define _USUARIO_H

typedef struct {
    char nome[101];
    int cpf;
} tUsuario;

tUsuario LeUsuario();

void PrintaNome(tUsuario usuario);

int RetornaCpf(tUsuario usuario);

#endif