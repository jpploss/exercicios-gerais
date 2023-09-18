#include "usuario.h"
#include <stdio.h>

tUsuario LeUsuario() {
    tUsuario usuario;
    scanf("%*[^\n]");
    scanf("%*c");

    scanf("%s %d", usuario.nome, &usuario.cpf);

    return usuario;
}

void PrintaNome(tUsuario usuario) {
    printf("%s\n", usuario.nome);
    return;
}

int RetornaCpf(tUsuario usuario) {
    return usuario.cpf;
}