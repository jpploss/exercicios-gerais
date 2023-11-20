#include "estabelecimento.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento {
    Vector* produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento() {
    tEstabelecimento* estab = malloc(sizeof(tEstabelecimento));
    estab->produtos = VectorConstruct();
    return estab;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento) {
    if(estabelecimento == NULL) return;

    VectorDestroy(estabelecimento->produtos, DestroiProduto);
    free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto) {
    VectorPushBack(estabelecimento->produtos, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento) {
    char nomeArq[101];
    scanf("%[^\n]", nomeArq);

    FILE* arquivo = fopen(nomeArq, "rb");
    if(!arquivo) {
        printf("Arquivo não encontrado.\n");
        exit(1);
    }
    
    int qtdProduto;
    fread(&qtdProduto, sizeof(int), 1, arquivo);    

    tProduto* produtoAux;
    for(int i = 0; i < qtdProduto; i++) {
        produtoAux = LeProduto(arquivo);
        AdicionaProdutoEstabelecimento(estabelecimento, produtoAux);
    }
    fclose(arquivo);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento) {
    int qtdProdutos = VectorSize(estabelecimento->produtos);
    tProduto* prodAux;
    int encontrouProd = 0;
    for(int i = 0; i < qtdProdutos; i++) {
        prodAux = VectorGet(estabelecimento->produtos, i);
        if(TemEstoqueProduto(prodAux)) continue;
        encontrouProd = 1;
        ImprimeProduto(prodAux);
        printf("\n");
    }
    if(!encontrouProd) printf("Nao ha produtos em falta!");
}
