#ifndef _FILME_H
#define _FILME_H

typedef struct {
    int codigo;
    int preco;
    char nome[20];
    int qtdFitas;
    int fitasDisponiveis;
} tFilme;

tFilme LeECadastraFilme(int codigo);

int ObtemCodigo(tFilme filme);
int ObtemQtdFitasDisponiveis(tFilme filme);
int ObtemPreco(tFilme filme);

int EhMesmoCodigo(tFilme filme1, int codigo);

int TemFitas(tFilme filme);

int TemMaximoDeFitas(tFilme filme);

int EhNomeMaior(tFilme filme1, tFilme filme2);

tFilme RetiraFita(tFilme filme);
tFilme DevolveFita(tFilme filme);

void PrintaNomeFilme(tFilme filme);

#endif