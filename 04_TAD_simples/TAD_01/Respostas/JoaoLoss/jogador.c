#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"
#include <stdio.h>

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada;
    int x, y;
    while(1) {
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);
        if(!EhPosicaoValidaTabuleiro(x, y)) {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            continue;
        } else if(!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            continue;
        }
        printf("Jogada [%d,%d]!\n", x, y);
        // se não entrou em nenhum dos if's, então a jogada foi bem sucedida e a posição estava livre
        break;
    }
    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
    return tabuleiro;   
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int i;

    for(i = 0; i < TAM_TABULEIRO; i++) {
        if(i == 1) { // verifica as diagonais
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador.id)) { // verifica se o centro (interseção das diagonais) está marcado
                // verifica a diagonal começando em (0,0)
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id)) {
                    return 1;
                } 
                // verifica a diagonal começando em (2, 0)
                else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id)) {
                    return 1;
                }
            }
        }
        // verifica a horizontal da linha i
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, i, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, i, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, i, jogador.id)) {
            return 1;
        } 
        // verifica a vertical da coluna i 
        else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 0, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 2, jogador.id)) {
            return 1;
        }
    } // fim do for
    return 0;
}
