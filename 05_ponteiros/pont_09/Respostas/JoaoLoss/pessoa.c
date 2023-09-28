#include "pessoa.h"
#include <stdio.h>


/**
 * @brief Cria uma nova pessoa e inicializa os ponteiros.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa) {
    *pessoa = CriaPessoa();
    scanf("%s", (*pessoa).nome);
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa) {
    if((*pessoa).pai == NULL || (*pessoa).mae == NULL) {
        return;
    }

    printf("NOME COMPLETO: %s\n", (*pessoa).nome);

    if((*pessoa).pai == NULL) printf("PAI: NAO INFORMADO\n");
    else printf("PAI: %s\n", (*((*pessoa).pai)).nome);

    if((*pessoa).mae == NULL) printf("MAE: NAO INFORMADO\n");
    else printf("MAE: %s\n", (*((*pessoa).mae)).nome);

    return;
}

/**
 * @brief Associa as famílias e grupos de pessoas.
 * Alem disso, e nessa funcao que sera lida a associacao entre as pessoas.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int qtdAcoes;
    scanf("%d", &qtdAcoes);

    int idMae, idPai, idFilho;
    for(int i = 0; i < qtdAcoes; i++) {
        scanf("mae: %d, pai: %d, filho: %d", &idMae, &idPai, &idFilho);
        scanf("%*[^m]");
        if(idPai != -1) pessoas[idFilho].pai = (pessoas + idPai);
        if(idMae != -1) pessoas[idFilho].mae = (pessoas + idMae);
    }
}
