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
    codigoFilme = ObtemCodigo(filme);
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigoFilme)) return 1;
    }
    return 0;
}

tEstoque AlugaFilme(tEstoque estoque, int codigo) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filme[i], codigo)) {
            estoque.filme[i] = RetiraFita(estoque.filme[i]);
            return estoque;
        }
    }
}

tEstoque DevolveFilme(tEstoque estoque, int codigo) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filme[i], codigo)) {
            estoque.filme[i] = DevolveFita(estoque.filme[i]);
            return estoque;
        }
    }
}

void PrintaEstoque(estoque) {
    printf("~ESTOQUE~\n");
    estoque = OrdenaPeloNomeEstoque(estoque);
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        PrintaFilme(estoque.filmes[i]);
    }

}
