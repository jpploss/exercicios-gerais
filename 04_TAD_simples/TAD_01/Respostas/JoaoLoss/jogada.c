#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>

/**
 * Lê uma jogada e retorna uma estrutura do tipo tJogada.
 * 
 * @return a jogada lida.
 */
tJogada LeJogada() {
    tJogada jogada;

    do {
        printf("Digite uma posicao (x e y):\n");
    } while(scanf("%d%d", &jogada.x, &jogada.y) != 2);

    if(!EhPosicaoValidaTabuleiro(jogada.x, jogada.y)) {
        jogada.sucesso = 0;
    } else {
        jogada.sucesso = 1;
    }
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