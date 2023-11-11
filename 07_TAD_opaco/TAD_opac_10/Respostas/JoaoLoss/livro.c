#include "livro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Livros {
    char* titulo;
    char* autor;
    int anoPub;
};

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro() {
    tLivros* livro = malloc(sizeof(tLivros));
    livro->anoPub = -1;
    livro->autor = NULL;
    livro->titulo = NULL;
    return livro;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro) {
    char titulo[50];
    char autor[50];

    scanf("%*[^A-Za-z]");
    scanf("%s", titulo);
    scanf("%*[^A-Za-z]");
    scanf("%s", autor);
    scanf("%d", &livro->anoPub);

    int tamString = strlen(titulo) + 1;
    livro->titulo = (char*)malloc(sizeof(char)*tamString);
    memcpy(livro->titulo, titulo, tamString*sizeof(char));

    tamString = strlen(autor) + 1;
    livro->autor = (char*)malloc(sizeof(char)*tamString);
    memcpy(livro->autor, autor, tamString*sizeof(char));
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->anoPub);
}

/**
 * Retorna o título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
*/
char *getTitulo(tLivros* livro) {
    return livro->titulo;
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro) {
    if(livro != NULL) {
        if(livro->autor != NULL) free(livro->autor);
        if(livro->titulo != NULL) free(livro->titulo);
        free(livro);
    }
}