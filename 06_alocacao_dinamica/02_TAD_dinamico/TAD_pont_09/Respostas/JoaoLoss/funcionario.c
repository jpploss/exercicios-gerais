#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

/**
 * @brief Cria um funcionario "vazio" 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TFuncionario Ponteiro para Funcionario criado a partir do nome e salario fornecidos.
 */
tFuncionario* CriaFuncionario() {
    tFuncionario* funcionario = (tFuncionario*) malloc(sizeof(tFuncionario));
    funcionario->id = -1;
    funcionario->salario = -1;
    return funcionario;
}

/**
 * @brief Libera a memória alocada dinamicamente por um funcionário
 * @param funcionario Ponteiro para Funcionario que terá sua memória liberada
 */
void ApagaFuncionario(tFuncionario* funcionario) {
    free(funcionario);
    return;
}

/**
 * @brief Le os dados de um funcionario da entrada padrao.
 * 
 * @param funcionario Funcionario criado a partir dos dados lidos.
 */
void LeFuncionario(tFuncionario* funcionario) {
    scanf("%d %f", &(funcionario->id), &(funcionario->salario));
    return;
}

/**
 * @brief Obtem o Id de um funcionario.
 * 
 * @param funcionario Funcionario que deseja obter o id.
 * @return int representando o id do funcionario fornecido.
 */
int GetIdFuncionario(tFuncionario* funcionario) {
    return funcionario->id;
}

/**
 * @brief Imprime todos os dados de um funcionario.
 * 
 * @param funcionario Funcionario a ser impresso no terminal.
 */
void ImprimeFuncionario(tFuncionario* funcionario) {
    printf("- Funcionario %d: RS %.02f\n", funcionario->id, funcionario->salario);
    return;
}