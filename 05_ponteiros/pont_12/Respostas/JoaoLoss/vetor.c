#include "vetor.h"
#include <stdio.h>
/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor) {
    scanf("%d", &((*vetor).tamanhoUtilizado));
    for(int i = 0; i < (*vetor).tamanhoUtilizado; i++) {
        scanf("%d", &((*vetor).elementos[i]));
    }
    return;
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    if((*vetor).tamanhoUtilizado == 1) {
        return (*vetor).elementos[0];
    }

    int res = op((*vetor).elementos[0], (*vetor).elementos[1]);
    for(int i = 2; i < (*vetor).tamanhoUtilizado; i++) {
        res = op(res, (*vetor).elementos[i]);
    }
    return res;
}