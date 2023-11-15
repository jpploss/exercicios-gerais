#include <stdio.h>
#include "tadgen.h"

int main() {
    int tipo;
    int qnt;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d", &tipo, &qnt);

    tGeneric* gen = CriaGenerico(tipo, qnt);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);
}