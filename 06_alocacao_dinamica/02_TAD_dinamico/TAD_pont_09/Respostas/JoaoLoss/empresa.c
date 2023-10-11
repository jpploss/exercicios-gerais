#include "funcionario.h"
#include "empresa.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa() {
    tEmpresa* empresa = (tEmpresa*) malloc(sizeof(tEmpresa));
    empresa->id = -1;
    empresa->qtdFuncionarios = -1;
    empresa->funcionarios = NULL;
    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa) {
    int numFuncionarios = 0;
    empresa->qtdFuncionarios = 0;
    scanf("%d %d", &(empresa->id), &numFuncionarios);

    tFuncionario* funcionarioAux = NULL;
    int idAtual = 0, idPassado = 0, jaCadastrado = 0;
    empresa->funcionarios = (tFuncionario**) malloc(sizeof(tFuncionario*) * empresa->qtdFuncionarios);
    for(int i = 0; i < numFuncionarios; i++) {
        funcionarioAux = CriaFuncionario();
        LeFuncionario(funcionarioAux);
        idAtual = GetIdFuncionario(funcionarioAux);
        jaCadastrado = 0;
        for(int j = 0; j < empresa->qtdFuncionarios; j++) {
            idPassado = GetIdFuncionario(*(((*empresa).funcionarios) + j));
            if(idPassado == idAtual) {
                jaCadastrado = 1;
                printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, idAtual);
                break;
            }
        }
        if(!jaCadastrado) {
            ContrataFuncionarioEmpresa(empresa, funcionarioAux);
        }
    }
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa) {
    for(int i = 0; i < empresa->qtdFuncionarios; i++) {
        ApagaFuncionario(*(empresa->funcionarios + i));
    }
    free(empresa->funcionarios);
    free(empresa);
    return;
}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario) {
    empresa->qtdFuncionarios += 1;
    empresa->funcionarios = (tFuncionario**) realloc(empresa->funcionarios, sizeof(tFuncionario*)*empresa->qtdFuncionarios);
    if(empresa->funcionarios == NULL) {
        printf("Problema na realocação de memória para os funcionários da empresa.\n");
        exit(1);
    }
    *(empresa->funcionarios + empresa->qtdFuncionarios - 1) = funcionario;
    return;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa) {
    printf("Empresa %d:\n", empresa->id);
    for(int i = 0; i < empresa->qtdFuncionarios; i++) {
        ImprimeFuncionario(*(empresa->funcionarios + i));
    }
    printf("\n");
    return;
}