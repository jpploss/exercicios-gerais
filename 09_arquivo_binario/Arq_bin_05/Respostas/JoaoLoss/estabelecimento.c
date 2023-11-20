#include "estabelecimento.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento {
    int qtdProdutos;
    tProduto** produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento() {
    tEstabelecimento* estab = malloc(sizeof(tEstabelecimento));
    if(estab == NULL) exit(1);
    estab->qtdProdutos = 0;
    estab->produtos = NULL;
    return estab;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento) {
    if(estabelecimento != NULL) {
        if(estabelecimento->produtos != NULL) {
            for(int i = 0; i < estabelecimento->qtdProdutos; i++) {
                DestroiProduto(estabelecimento->produtos[i]);
            }
            free(estabelecimento->produtos);
        }
        free(estabelecimento);
    }
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto) {
    estabelecimento->qtdProdutos += 1;
    estabelecimento->produtos = realloc(estabelecimento->produtos, sizeof(tProduto*)*estabelecimento->qtdProdutos);
    if(estabelecimento->produtos == NULL) exit(1);
    estabelecimento->produtos[estabelecimento->qtdProdutos - 1] = produto;
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento) {
    char arq[101];
    scanf("%s", arq);
    FILE* arquivo = fopen(arq, "rb");

    int* qtdProd;
    fread(qtdProd, sizeof(int), 1, arquivo);

}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento);
