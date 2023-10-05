#include "rolagem.h"
#include <stdio.h>

void LeMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs) {
    for(int i = 0; i < *numMsgs; i++) {
        printf("Digite a mensagem %d: ", i + 1);
        scanf("%[^\n]", msg[i]);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    printf("Mensagens recebidas.\n");
    return;
}

int main() {
    int tam, qtdDeslocamentos;
    printf("Diga quantos caracteres cabe no seu painel: ");
    scanf("%d", &tam);
    printf("O seu painel tem %d caracteres. Quantos deslocamentos você deseja: ", tam);
    scanf("%d", &qtdDeslocamentos);

    RolaMsg(LeMensagens, tam, qtdDeslocamentos);
    return 0;
}