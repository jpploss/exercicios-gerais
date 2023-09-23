#include "estoque.h"
#include <stdio.h>

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

int TemCodigoNoCadastro(int codigo, tEstoque estoque) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigo)) {
           return 1; 
        }
    }
    return 0;
}

tEstoque AlugaFilme(tEstoque estoque, int codigo) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigo)) {
            estoque.filmes[i] = RetiraFita(estoque.filmes[i]);
        }
    }
    return estoque;
}

tEstoque DevolveFilme(tEstoque estoque, int codigo) {    
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigo)) {
            estoque.filmes[i] = DevolveFita(estoque.filmes[i]);
            printf("Filme %d - ", codigo);
            PrintaNomeFilme(estoque.filmes[i]);
            printf(" Devolvido!\n");
            return estoque;
        }
    }
}

void PrintaEstoque(tEstoque estoque) {
    int codigo, qtdFitas;
    printf("~ESTOQUE~\n");
    estoque = OrdenaPeloNomeEstoque(estoque);
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        codigo = ObtemCodigo(estoque.filmes[i]);
        qtdFitas = ObtemQtdFitasDisponiveis(estoque.filmes[i]);
        printf("%d - ", codigo);
        PrintaNomeFilme(estoque.filmes[i]);
        printf(" Fitas em estoque: %d\n", qtdFitas);
    }
}

tEstoque CadastroDeFilme(tEstoque estoque, int codigo) {
    if(TemCodigoNoCadastro(codigo, estoque)) {
        printf("Filme ja cadastrado no estoque\n");
        return estoque;
    }

    estoque.filmes[estoque.qtdFilmes] = LeECadastraFilme(codigo);
    estoque.qtdFilmes++;
    return estoque;
}

tFilme ObtemFilme(tEstoque estoque, int codigo) {
    for(int i = 0; i < estoque.qtdFilmes; i++) {
        if(EhMesmoCodigo(estoque.filmes[i], codigo)) {
            return estoque.filmes[i];
        }
    }
}