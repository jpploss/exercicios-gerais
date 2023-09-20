#include "filme.c"

typedef struct {
    tFilme filmes[100];
    int qtdFilmes;
} tEstoque;

tEstoque InicializaEstoque(tEstoque estoque) {
    estoque.qtdFilmes = 0;
    return estoque;
}

tEstoque OrdenaPeloNomeEstoque(tEstoque estoque) {
    tFilme aux;
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        for(int j = i + 1; j < estoque.qtdFilmes; j++) {
            if(NomeMaiorNoAlfabeto(estoque.filmes[i], estoque.filmes[j])) {
                aux = estoque.filmes[i];
                estoque.filmes[i] = estoque.filmes[j];
                estoque.filmes[j] = aux;
            }
        }
    }
    return estoque;
}

int TemCodigoNoCadastro(tFilme filme, tEstoque estoque) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(filme, estoque.filmes[i])) return 1;
    }
    return 0;
}