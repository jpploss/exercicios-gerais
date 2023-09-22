#include "estoque.h"

tEstoque InicializaEstoque(tEstoque estoque) {
    estoque.qtdFilmes = 0;
    return estoque;
}

tEstoque OrdenaPeloNomeEstoque(tEstoque estoque) {
    tFilme aux;
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        for(int j = i + 1; j < estoque.qtdFilmes; j++) {
            if(EhNomeMaior(estoque.filmes[i], estoque.filmes[j])) {
                aux = estoque.filmes[i];
                estoque.filmes[i] = estoque.filmes[j];
                estoque.filmes[j] = aux;
            }
        }
    }
    return estoque;
}

int TemCodigoNoCadastro(tFilme filme, tEstoque estoque) {
    int codigoFilme = ObtemCodigo(filme);
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigoFilme)) return 1;
    }
    return 0;
}

tEstoque AlugaFilme(tEstoque estoque, int codigo) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigo)) {
            estoque.filmes[i] = RetiraFita(estoque.filmes[i]);
            return estoque;
        }
    }
}

tEstoque DevolveFilme(tEstoque estoque, int codigo) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigo)) {
            estoque.filmes[i] = DevolveFita(estoque.filmes[i]);
            return estoque;
        }
    }
}

void PrintaEstoque(tEstoque estoque) {
    printf("~ESTOQUE~\n");
    estoque = OrdenaPeloNomeEstoque(estoque);
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        PrintaFilme(estoque.filmes[i]);
    }
}

tEstoque ColocaNoEstoqueFilme(tEstoque estoque, tFilme filme) {
    estoque.filmes[estoque.qtdFilmes] = filme;
    estoque.qtdFilmes++;
    return estoque;
}
