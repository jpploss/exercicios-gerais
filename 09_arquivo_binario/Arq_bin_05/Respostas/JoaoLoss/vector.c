#include "vector.h"
#include <stdlib.h>

struct Vector {
    int tamVet;
    DataType* vet;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct() {
    Vector* vet = malloc(sizeof(Vector));
    if(vet == NULL) exit(1);
    vet->tamVet = 0;
    vet->vet = NULL;
    return vet;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val) {
    v->tamVet += 1;
    v->vet = realloc(v->vet, sizeof(DataType) * v->tamVet);
    if(v->vet == NULL) exit(1);
    v->vet[v->tamVet - 1] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i) {
    return v->vet[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v) {
    return v->tamVet;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    if(v == NULL) return;
    if(v->vet == NULL) return;

    for(int i = 0; i < v->tamVet; i++) {
        destroy(v->vet[i]);
    }
    free(v->vet);
    free(v);
}