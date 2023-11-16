#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct soma {
    float n1, n2;
};

/**
 * @brief Cria uma tarefa do tipo soma de dois números
 * 
 * @param n1 - Primeiro número que será somado quando a tarefa for executada
 * @param n2 - Segundo número que será somado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tSoma* CriaTarefaSoma(float n1, float n2) {
    tSoma* soma = malloc(sizeof(tSoma));
    soma->n1 = n1;
    soma->n2 = n2;
    return soma;
}

/**
 * @brief Função que executa uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaSoma(void *sum) {
    tSoma* sumTipado = (tSoma*) sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", sumTipado->n1, sumTipado->n2, sumTipado->n1 + sumTipado->n2);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaSoma(void *sum) {
    tSoma* sumTipado = (tSoma*) sum;
    if(sumTipado != NULL) {
        free(sumTipado);
    }
}
