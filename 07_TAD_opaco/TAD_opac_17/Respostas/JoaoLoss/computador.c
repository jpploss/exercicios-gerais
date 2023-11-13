#include "computador.h"
#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

struct Computador {
    int derrotas, vitorias;    
}; 

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tComputador
 * 
 * @return A variável do tipo Computador inicializada.
 */
tComputador* CriaComputador() {
    tComputador* pc = (tComputador*)malloc(sizeof(tComputador));
    pc->derrotas = 0;
    pc->vitorias = 0;
    return pc;
}

/**
 * @brief Libera toda a memória alocada para uma variável do tipo computador.
 * 
 * @param comp - A variável do tipo Computador que terá sua memória liberada
 */
void DestroiComputador(tComputador* comp) {
    free(comp);
}

/**
 * @brief Função que gerencia o jogo. Recebe os dados da entrada padrão, os processa e "lida" com as funções necessárias de jogo.
 * 
 * @param computador - Variável computador que salvará o "log" das jogadas, para mostrar o relatório final (apresentado no roteiro)
 */
void GerenciaJogo(tComputador *computador) {
    int numFornecido = 0, min, max, resultado;
    tJogo* jogo = CriaJogo();

    int input = 1;
    while(numFornecido < 1 || numFornecido > 10000 || input != 1) {
        printf("Forneca um numero no intervalo entre 1 e 10000:\n");
        input = scanf("%d", &numFornecido);
    }

    printf("Forneca um intervalo de numeros naturais:\n");
    scanf("%d %d", &min, &max);
    DefineMaximo(jogo, max);
    DefineMinimo(jogo, min);
    CalculaNumeroTentativas(jogo);
    CalculaValorASerAdivinhado(jogo, numFornecido);
    
    resultado = ProcessaTentativas(jogo);
    DestroiJogo(jogo);

    if(resultado) computador->vitorias += 1;
    else computador->derrotas += 1;

}

/**
 * @brief Imprime o relatório "da rodada", mostrado quandoDefine o valor máximo do intervalo que o jogo deve considerar o jogador não deseja jogar novamente, como mostra o roteiro.
 * 
 * @param computador - A variável do tipo computador que terá seus dados apresentados em tela.
 */
void ImprimeRelatorio(tComputador* computador) {
    printf("Obrigado por jogar comigo. Desta vez, voce jogou %d jogo(s), ganhou %d jogo(s) e perdeu %d jogo(s). Ate a proxima!\n", computador->derrotas+computador->vitorias, computador->vitorias, computador->derrotas);
}