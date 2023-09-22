#include <string.h>
#include <stdio.h>
#include "filme.h"

tFilme LeECadastraFilme(int codigo) {
    tFilme filme;
    filme.codigo;
    scanf("%[^,],%d,%d", filme.nome, &filme.preco, &filme.qtdFitas);
    filme.fitasDisponiveis = filme.qtdFitas;
    printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);
    return filme;
}

int ObtemCodigo(tFilme filme) {
    return filme.codigo;
}

int ObtemPreco(tFilme filme) {
    return filme.preco;
}

int EhMesmoCodigo(tFilme filme1, int codigo) {
    if(filme1.codigo == codigo) return 1;
    return 0;
}

int TemFitas(tFilme filme) {
    if(filme.fitasDisponiveis >= 1) return 1;
    return 0;
}

int TemMaximoDeFitas(tFilme filme) {
    if(filme.qtdFitas == filme.fitasDisponiveis) return 1;
    return 0;
}

int EhNomeMaior(tFilme filme1, tFilme filme2) {
    if(strcmp(filme1.nome, filme2.nome) > 0) return 1;
    return 0;
}

tFilme RetiraFita(tFilme filme) {
    filme.fitasDisponiveis -= 1;
    return filme;
}

tFilme DevolveFita(tFilme filme) {
    filme.fitasDisponiveis += 1;
    return filme;
}

void PrintaFilme(tFilme filme) {
    printf("%d - %s em estoque: %d\n", filme.codigo, filme.nome, filme.fitasDisponiveis);
    return;
}