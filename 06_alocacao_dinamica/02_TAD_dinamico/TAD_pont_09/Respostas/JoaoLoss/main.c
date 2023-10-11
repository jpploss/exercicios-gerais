#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main() {
    int qtdEmpresas;
    scanf("%d", &qtdEmpresas);

    tEmpresa** empresas = (tEmpresa**) malloc(sizeof(tEmpresa*)*qtdEmpresas);

    if(empresas == NULL) {
        printf("Problema na alocação de memória para receber as empresas.\n");
        exit(1);
    }

    for(int i = 0; i < qtdEmpresas; i++) {
        *(empresas + i) = CriaEmpresa();
        LeEmpresa(*(empresas + i));
    }

    for(int i = 0; i < qtdEmpresas; i++) {
        ImprimeEmpresa(*(empresas + i));
    }

    for(int i = 0; i < qtdEmpresas; i++) {
        ApagaEmpresa(*(empresas + i));
    }

    free(empresas);

    return 0;
}