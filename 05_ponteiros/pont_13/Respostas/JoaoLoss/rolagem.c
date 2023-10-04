#include "rolagem.h"
#include <stdio.h>

/**
 * @brief Ponteiro para função que recebe um array de mensagens e o número de mensagens para rolagem.
 * 
 * @param msg Array de mensagens.
 * @param numMsgs Número de mensagens.
 */
typedef void (*FptrMsg)(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

/**
 * @brief Dispara a função de rolagem de mensagens.
 * 
 * @param FuncMsg Ponteiro para a função que recebe um array de mensagens e o número de mensagens.
 * @param tamanhoDisplay Tamanho do display.
 * @param tempoFim Tempo de duração da rolagem.
 */
void RolaMsg(int tamanhoDisplay, int tempoFim) {
    int qtdMsg;
    scanf("%d", &qtdMsg);
    scanf("%*[^\n]");
    scanf("%*c");

    char painel[31];
    char mensagens[qtdMsg][TAM_MAX_MSG];

    for(int i = 0; i < qtdMsg; i++) {
        scanf("%[^\n]", mensagens[i]);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    int apontaMsg = 0, letra = 0;
    for(int i = 0; i < tempoFim; i++) {
        for(int j = 0; j < 30; j++) {
            if(*(*(mensagens + apontaMsg) + letra) == 0) { // se chegou no fim de uma palavra
                if(apontaMsg == (qtdMsg - 1)) { // se está no fim da última mensagem o apontaMsg deve apontar para o início
                    apontaMsg = 0;
                } else { // se não, deve apontar para a próxima mensagem
                    apontaMsg++;
                }
                letra = 0;
                painel[j] = '\t';
                continue;
            }
            painel[j] = *(*(mensagens + apontaMsg) + letra);
            letra++;
        }

        painel[30] = 0;
        printf("%s", painel);

        for(int x = 0; x < 10000; x++);
        printf("\033[H\033[J");

        // só para dar um delay
        for(int x = 0; x < 10000; x++);
    }
}
