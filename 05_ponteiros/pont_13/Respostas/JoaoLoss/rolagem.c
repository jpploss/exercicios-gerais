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
    printf("%s", painel);

    // faz os delocamentos
    for(int i = 0; i < tempoFim; i++) {
        char letraPassada = painel[0], letraAtual;
        for(int j = 1; j < tamanhoDisplay; j++) {
            letraAtual = painel[j];
            painel[j] = letraPassada;
            letraPassada = letraAtual;
        }
        if(*(*(mensagens + apontaMsg) + letra) == 0) { // se chegou no fim de uma palavra
            if(apontaMsg == (qtdMsg - 1)) { // se está no fim da última mensagem o apontaMsg deve apontar para o início
                apontaMsg = 0;
            } else { // se não, deve apontar para a próxima mensagem
                apontaMsg++;
            }
            letra = 0;
            painel[0] = ' ';
            continue;
        }
        painel[0] = *(*(mensagens + apontaMsg) + letra);
        letra++;

        // faz um delay
        for(int d = 0; d < 100000; d++);

        // limpa o terminal e imprime o novo conteúdo do painel
        printf("\033[H\033[J");
        printf("%s", painel);
    }

    

    // // só para dar um delay
    // for(int x = 0; x < 10000; x++);
}
