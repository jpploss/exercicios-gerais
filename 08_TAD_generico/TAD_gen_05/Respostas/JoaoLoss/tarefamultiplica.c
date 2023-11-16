#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mult {
    float n1, n2;
};

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2) {
    tMult* m = malloc(sizeof(tMult));
    m->n1 = n1;
    m->n2 = n2;
    return m;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult) {
    tMult* multTipado = (tMult*) mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", multTipado->n1, multTipado->n2, multTipado->n1 * multTipado->n2);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult) {
    tMult* multTipado = (tMult*) mult;
    if(multTipado != NULL) {
        free(multTipado);
    }
}