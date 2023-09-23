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

    int codigo;
    int lucroTotal = 0, lucroPorAluguel = 0, qtdAlugados = 0;
    while(scanf("%s", acao) == 1) {
        if(strcmp(acao, strCadastrar) == 0) {
            while(scanf("%d,", &codigo) == 1) {
                estoque = CadastroDeFilme(estoque, codigo);
            }
            printf("\n");

        } else if(strcmp(acao, strEstoque) == 0) {
            PrintaEstoque(estoque);
            printf("\n");

        } else if(strcmp(acao, strAlugar) == 0) {
            lucroPorAluguel = 0;
            qtdAlugados = 0;
            while(scanf("%d", &codigo) == 1) {
                if(!TemCodigoNoCadastro(codigo, estoque)) {
                    printf("Filme %d nao cadastrado.\n", codigo);
                    continue;
                }
                filme = ObtemFilme(estoque, codigo);
                if(TemFitas(filme)) {
                    estoque = AlugaFilme(estoque, codigo);
                    lucroPorAluguel += ObtemPreco(filme);
                    qtdAlugados++;
                } else {
                    printf("Filme %d - ", codigo);
                    PrintaNomeFilme(filme);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
            }
            if(lucroPorAluguel) {
               printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, lucroPorAluguel); 
            }        
            printf("\n");

        } else if(strcmp(acao, strDevolver) == 0) {
            while(scanf("%d", &codigo) == 1) {
                if(!TemCodigoNoCadastro(codigo, estoque)) {
                    printf("Filme %d nao cadastrado.\n", codigo);
                    continue;
                }
                filme = ObtemFilme(estoque, codigo);
                if(!TemMaximoDeFitas(filme)) {
                    estoque = DevolveFilme(estoque, codigo);
                    lucroTotal += ObtemPreco(filme);
                } else {
                    printf("Nao e possivel devolver o filme %d - ", codigo);
                    PrintaNomeFilme(filme);
                    printf(".\n");
                }
                
            }
            printf("\n");
        }

        scanf("%*[^#]"); //limpa o '#'
        scanf("%*[^\n]");
        scanf("%*c");
    }
    if(lucroTotal) printf("Lucro total R$%d\n", lucroTotal);

    return 0;
}