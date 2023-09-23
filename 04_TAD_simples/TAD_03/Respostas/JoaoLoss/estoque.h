#ifndef _ESTOQUE_H
#define _ESTOQUE_H

#include "filme.h"

typedef struct {
    tFilme filmes[100];
    int qtdFilmes;
} tEstoque;

tEstoque InicializaEstoque(tEstoque estoque);

tEstoque OrdenaPeloNomeEstoque(tEstoque estoque);

int TemCodigoNoCadastro(int codigo, tEstoque estoque);

tEstoque AlugaFilme(tEstoque estoque, int codigo);

tEstoque DevolveFilme(tEstoque estoque, int codigo);

void PrintaEstoque(tEstoque estoque);

tEstoque CadastroDeFilme(tEstoque estoque, int codigo);

tFilme ObtemFilme(tEstoque estoque, int codigo);

#endif