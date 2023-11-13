#include "computador.h"
#include <stdio.h>

int main() {
    char replay = 0;

    printf("Jogo de adivinhação\n");

    tComputador* pc = CriaComputador();
    while(1) {
        GerenciaJogo(pc);

        while(1) {
            printf("Deseja continuar a jogar (s/n):\n");
            scanf("%*[^\n]");
            scanf("%*c");
            scanf("%c", &replay);
            if(replay == 's' || replay == 'n') break;
            printf("Voce deve digitar s ou n!\n");
        }
        if(replay == 'n') break;
    }
    
    ImprimeRelatorio(pc);
    DestroiComputador(pc);

    return 0;
}