#include "tabuleiro.h"
#include <stdio.h>

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 * 
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro() {
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'X'; // 'X'
    tabuleiro.peca2 = '0'; // '0'
    tabuleiro.pecaVazio = '-';
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++) {
        for(j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro.posicoes[i][j] = '-';
        }
    }
    return tabuleiro;
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 * 
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    if(peca == PECA_1) {
        tabuleiro.posicoes[y][x] = 'X';
    } else if(peca == PECA_2) {
        tabuleiro.posicoes[y][x] = '0';
    }
    return tabuleiro;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++) {
        for(j = 0; j < TAM_TABULEIRO; j++) {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, j, i)) {
                return 1;
            }
        }
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    if(peca == PECA_1) {
        if(tabuleiro.posicoes[y][x] == 'X') {
            return 1;
        }
        return 0;
    }
    if(tabuleiro.posicoes[y][x] == '0') {
        return 1;
    }
    return 0;        
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    if(tabuleiro.posicoes[y][x] == '-') return 1;
    return 0;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y) {
    if(x >= 3 || x < 0 || y >= 3 || y < 0) return 0;
    return 1;
}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++) {
        printf("\t");
        for(j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
    return;
}