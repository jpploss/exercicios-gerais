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
    int qtdMsg;
    scanf("%d", &qtdMsg);
    scanf("%*[^\n]");
    scanf("%*c");

    char painel[tamanhoDisplay + 1];

    char mensagens[qtdMsg][TAM_MAX_MSG];
    FuncMsg(mensagens, &qtdMsg);

    // iniciar o conteúdo do painel

    int apontaMsg = 0, letra = 0;
    for(int j = 0; j < tamanhoDisplay; j++) {
        if(*(*(mensagens + apontaMsg) + letra) == 0) { // se chegou no fim de uma palavra
            if(apontaMsg == (qtdMsg - 1)) { // se está no fim da última mensagem o apontaMsg deve apontar para o início
                apontaMsg = 0;
            } else { // se não, deve apontar para a próxima mensagem
                apontaMsg++;
            }
            letra = 0;
            painel[j] = ' ';
            continue;
        }
        painel[j] = *(*(mensagens + apontaMsg) + letra);
        letra++;
    }
    painel[tamanhoDisplay] = 0;
    printf("\033[H\033[J");
    printf("%s\n", painel);

    // faz os delocamentos
    for(int i = 0; i < tempoFim; i++) {
        //desloca
        int proxima;
        for(int j = 0; j < tamanhoDisplay; j++) {
            proxima = j + 1;
            painel[j] = painel[proxima];
        }

        // coloca a próxima letra no final do painel
        if(mensagens[apontaMsg][letra] == 0) {
            if(apontaMsg == qtdMsg - 1) {
                apontaMsg = 0;
            } else apontaMsg++;
            letra = 0;
            painel[29] = ' ';
        } else {
            painel[29] = mensagens[apontaMsg][letra];
            letra++;
        }

        // faz um delay
        for(int d = 0; d < 150000000; d++);

        // limpa o terminal e imprime o novo conteúdo do painel
        printf("\033[H\033[J");
        printf("%s\n", painel);
    }

    

    // // só para dar um delay
    // for(int x = 0; x < 10000; x++);
}
