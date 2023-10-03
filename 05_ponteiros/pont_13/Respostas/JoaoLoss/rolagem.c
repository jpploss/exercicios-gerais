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
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim) {
    for(int i = 0; i < tempoFim; i++) {
        printf("\033[H\033[J");
    }
}
