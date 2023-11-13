#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Jogo
{
    int max, min;
    int numDoJogo;
    int nTentativas;
};


/**
 * @brief Cria uma variável do tipo jogo
 * 
 * @return Uma variável do tipo jogo inicializada.
 */
tJogo* CriaJogo() {
    tJogo* jogo = (tJogo*)malloc(sizeof(tJogo));
    jogo->nTentativas = 0;
    jogo->max = 0;
    jogo->min = 0;
    jogo->numDoJogo = 0;
    return jogo;
}

/**
 * @brief Libera toda a memória alocada para um jogo.
 * 
 * @param jogo - A variável do tipo jogo que será liberada.
 */
void DestroiJogo(tJogo* jogo) {
    free(jogo);
}

/**
 * @brief Define o valor máximo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param max - o valor máximo do intervalo do jogo.
 */
void DefineMaximo(tJogo* jogo, int max) {
    jogo->max = max;
}

/**
 * @brief Define o valor mínimo do intervalo que o jogo deve considerar
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param min - o valor mínimo do intervalo do jogo.
 */
void DefineMinimo(tJogo* jogo, int min) {
    jogo->min = min;
}

int EhPrimo(int num) {
    int div = 0;
    for(int i = 2; i < num; i++) {
        if(num%i == 0) return 0;
    }
    return 1;
}

/**
 * @brief Calcula o número a ser adivinhado pelo jogador
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaValorASerAdivinhado(tJogo *jogo, int n) {
    int atual = 1;
    int anterior = 0;
    int anteriorDoAnterior = 0;
    int somaPrimos = 0;
    
    while(1) {
        if(EhPrimo(atual)) {
            somaPrimos += 1;
            if(somaPrimos == n) {
                jogo->numDoJogo = atual;
                return;
            }
        }
        
        anteriorDoAnterior = anterior;
        anterior = atual;
        atual = anterior + anteriorDoAnterior;
    }
}

/**
 * @brief Calcula o número de tentativas que o usuário irá ter para acertar o número. 
 * O cálculo deve ser feito como descrito no roteiro.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaNumeroTentativas(tJogo *jogo) {
    int aux = jogo->max - jogo->min + 1;
    int mc =  (int)(log2(aux) + 1);
    jogo->nTentativas = mc;
}

/**
 * @brief Executa o jogo. Calcula o que for necessário e lê as tentativas, fazendo as devidas verificações.
 * 
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados.
 * @return int 1 se o usuário venceu o jogo ou 0 caso contrário
 */
int ProcessaTentativas(tJogo* jogo) {
    int somaTentativas = 0, chute;
    printf("Voce tem direito a %d tentativas\n", jogo->nTentativas);
    while (somaTentativas != jogo->nTentativas)
    {
        somaTentativas += 1;
        printf("Tentativa %d:\n", somaTentativas);
        scanf("%d", &chute);

        if(chute > jogo->numDoJogo) printf("Alta\n");
        else if(chute < jogo->numDoJogo) printf("Baixa\n");
        else {
            printf("Parabens, voce ganhou!\n");
            return 1;
        }
    }
    printf("Voce perdeu! O numero escolhido foi %d\n", jogo->numDoJogo);
    return 0;
}
