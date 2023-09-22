#ifndef _ESTOQUE_H
#define _ESTOQUE_H

#include "filme.h"

typedef struct {
    tFilme filmes[100];
    int qtdFilmes;
} tEstoque;

tEstoque InicializaEstoque(tEstoque estoque);

tEstoque OrdenaPeloNomeEstoque(tEstoque estoque);

int TemCodigoNoCadastro(tFilme filme, tEstoque estoque);

tEstoque AlugaFilme(tEstoque estoque, int codigo);

tEstoque DevolveFilme(tEstoque estoque, int codigo);

void PrintaEstoque(tEstoque estoque);

tEstoque ColocaNoEstoqueFilme(tEstoque estoque, tFilme filme);

#endif