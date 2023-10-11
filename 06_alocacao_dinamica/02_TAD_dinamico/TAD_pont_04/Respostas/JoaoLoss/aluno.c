#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

/**
 * @brief Cria um novo aluno vazio. Os atributos inteiros devem receber valor -1, e o ponteiro do nome deve apontar para NULL;
 * 
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno* CriaAluno() {
    tAluno* alunoPont = (tAluno*) malloc(sizeof(tAluno));
    if(alunoPont == NULL) {
        printf("Problema na alocação de memória para aluno.\n");
        exit(1);
    }
    alunoPont->nome = NULL;
    alunoPont->n1 = -1;
    alunoPont->n2 = -1;
    alunoPont->n3 = -1;
    alunoPont->matricula = -1;
    return alunoPont;
}

/**
 * @brief Função para liberar toda a memória alocada dinamicamente para estrututas do tipo tAluno
 * 
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno) {
    //free(aluno->nome);
    free(aluno);
    return;
}


/**
 * @brief Lê os dados de um aluno.
 * 
 * @param Ponteiro para aluno (alocado dinamicamente), cujos dados serão preenchidos nessa função
 */
void LeAluno(tAluno *aluno) {
    scanf("%*[^A-Za-z]");

    /*char nomeAux[40];
    scanf("%s", nomeAux);
    printf("%s\n", nomeAux);
    aluno->nome = nomeAux;*/

    int tamanho = 0, letra;

    letra = getchar();
    while(letra != '\n' && letra != EOF) {
        tamanho++;
        aluno->nome = realloc((*aluno).nome, tamanho);
        *((aluno->nome) + tamanho - 1) = letra;
        letra = getchar();
    }
    tamanho++;
    aluno->nome = realloc((*aluno).nome, tamanho);
    *((aluno->nome) + tamanho - 1) = '\0';

   

    scanf("%d %d %d %d", &(aluno->matricula), &(aluno->n1), &(aluno->n2), &(aluno->n3));
    return;
}

/**
 * @brief Compara as matrículas de dois alunos.
 * 
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2) {
    if(aluno1->matricula > aluno2->matricula) return 1;
    if(aluno1->matricula < aluno2->matricula) return -1;
    if(aluno1->matricula == aluno2->matricula) return 0;
}

/**
 * @brief Calcula a média das notas de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno* aluno) {
    int soma = aluno->n1 + aluno->n2 + aluno->n3;
    return soma/3;
}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 * 
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno* aluno) {
    int media = CalculaMediaAluno(aluno);
    if(media >= 7) return 1;
    return 0;
}

/**
 * @brief Imprime os dados de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno* aluno) {
    printf("%s\n", aluno->nome);
    return;
}
