#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"
#include <stdio.h>


/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo() {
    tJogo jogo;
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();
    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo) {
    while(1) {
        // jogador 1:
        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
            printf("JOGADOR 1 Venceu!\n");
            return;
        } else if(AcabouJogo(jogo)) break;

        // jogador 2:
        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
            printf("JOGADOR 2 Venceu!\n");
            return;
        } else if(AcabouJogo(jogo)) break;
    }
    printf("Sem vencedor!\n");
    return;
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo) {
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        return 0;
    }
    return 1;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
    char opcao;
    printf("Jogar novamente? (s,n)\n");
    while(1) {
        scanf("%*[^\n]");
        scanf("%*c");

        scanf("%c", &opcao);
        if(opcao == 's') {
            return 1;
        } else if(opcao == 'n') {
            return 0;
        }
    }    
}