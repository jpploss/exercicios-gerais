#include "biblioteca.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Estrutura que representa uma biblioteca de livros
struct Biblioteca {
    tLivros** livros;
    int qtdLivros;
};


/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca() {
    tBiblioteca* biblio = malloc(sizeof(tBiblioteca));
    biblio->livros = NULL;
    biblio->qtdLivros = 0;
    return biblio;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca) {
    if(biblioteca != NULL) {
        if(biblioteca->livros != NULL) {
            for(int i = 0; i < biblioteca->qtdLivros; i++) ApagaLivro(biblioteca->livros[i]);
            free(biblioteca->livros);
        }
        free(biblioteca);
    }
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro) {
    biblioteca->qtdLivros += 1;
    biblioteca->livros = (tLivros**)realloc(biblioteca->livros, sizeof(tLivros*)*biblioteca->qtdLivros);
    biblioteca->livros[biblioteca->qtdLivros-1] = livro;
    printf("Livro adicionado com sucesso!\n");
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo) {
    int qtdLivros = biblioteca->qtdLivros;
    char* tituloAtual = NULL;

    for(int i = 0; i < qtdLivros; i++) {
        if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo)) {
            ApagaLivro(biblioteca->livros[i]);
            for(int j = i; j < qtdLivros-1; j++) {
                biblioteca->livros[j] = biblioteca->livros[j+1];
                biblioteca->livros[j+1] = NULL;
            }
            biblioteca->qtdLivros -= 1;
            biblioteca->livros = (tLivros**)realloc(biblioteca->livros, sizeof(tLivros*)*biblioteca->qtdLivros);
            printf("Livro removido com sucesso!\n");
            return;
        }
    }

    printf("Livro nao encontrado na biblioteca.\n");
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo) {
    char* tituloAux = getTitulo(livro);
    return strcmp(titulo, tituloAux);
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca) {
    if(biblioteca->qtdLivros >= 1) {
        printf("\nLista de Livros na Biblioteca:\n");
        for(int i = 0; i < biblioteca->qtdLivros; i++) {
            ImprimeLivro(biblioteca->livros[i]);
        }
    } else {
        printf("A biblioteca esta vazia!\n");
    }
    
}