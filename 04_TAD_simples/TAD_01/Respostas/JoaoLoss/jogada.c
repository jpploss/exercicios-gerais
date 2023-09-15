#include "jogada.h"
#include <stdio.h>

/**
 * Lê uma jogada e retorna uma estrutura do tipo tJogada e define o valor da variavel sucesso.
 * Se a jogada foi lida com sucesso, ou seja, foi lido um valor para x e outro para y, sucesso = 1, caso contrário, sucesso = 0.
 * @return a jogada lida.
 */
tJogada LeJogada() {
    tJogada jogada;
    int retornoScanf;
    do {
        printf("Digite uma posicao (x e y):\n");
        retornoScanf = scanf("%d%d", &jogada.x, &jogada.y);

        // se nn limpar o buffer o scanf retorna "0" automaticamente (pq ele vai tentar ler o que nn conseguiu da vez passada), entrando em loop infinito
        scanf("%*[^\n]");
        scanf("%*c");

    } while(retornoScanf != 2);
    jogada.sucesso = 1;
    return jogada;
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a jogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada jogada) {
    return jogada.sucesso;
}