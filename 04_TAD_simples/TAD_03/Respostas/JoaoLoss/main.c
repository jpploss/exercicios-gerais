#include "filme.h"
#include "estoque.h"
#include <string.h>
#include <stdio.h>

int main() {
    char strCadastrar[20] = "Cadastrar";
    char strEstoque[20] = "Estoque";
    char strAlugar[20] = "Alugar";
    char strDevolver [20] = "Devolver";

    char acao[20]; 

    tFilme filme;
    tEstoque estoque;
    estoque = InicializaEstoque(estoque);

    while(scanf("%s", acao) == 1) {
        if(strcmp(acao, strCadastrar) == 0) {
            int codigo;
            while(scanf("%d,", &codigo) == 1) {
                filme = LeECadastraFilme(codigo);
                estoque = ColocaNoEstoqueFilme(estoque, filme);
            }

            scanf("%*[^\n]"); //limpa o '#'
            scanf("%*c");
        } else if(strcmp(acao, strEstoque) == 0) {
            PrintaEstoque(estoque);
        } else if(strcmp(acao, strAlugar) == 0) {
            int codigo;
            while(scanf("%d", &codigo) == 1) {
                // verifica se pode alugar
            }

            scanf("%*[^\n]"); //limpa o '#'
            scanf("%*c");
        }
    }
}