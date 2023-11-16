#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct impr {
    char* msg;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg) {
    tImpr* imp = malloc(sizeof(tImpr));

    int tamBytesMsg = (strlen(msg)+1)*sizeof(char);
    imp->msg = malloc(tamBytesMsg);
    memcpy(imp->msg, msg, tamBytesMsg);

    return imp;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp) {
    tImpr* impTipado = (tImpr*)imp;
    printf("\n%s", impTipado->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp) {
    tImpr* impTipado = (tImpr*)imp;
    if(impTipado != NULL) {
        if(impTipado->msg != NULL) free(impTipado->msg);
        free(impTipado);
    }
}
