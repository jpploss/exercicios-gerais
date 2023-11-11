#include <stdio.h>
#include "biblioteca.h"
#include "livro.h"

void PrintaMenu() {
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");
}

int main() {
    int qntOp, opAtual;
    char tituloAux[50];
    scanf("%d", &qntOp);

    tBiblioteca* biblioteca = InicializarBiblioteca();
    tLivros* livroAux;
    
    PrintaMenu();
    for(int i = 0; i < qntOp; i++) {
        scanf("%d", &opAtual);
        if(opAtual != 1 && opAtual != 2 && opAtual != 3) {
            printf("Operacao invalida!\n");
            break;
        }
        switch (opAtual)
        {
        case 1:
            livroAux = CriaLivro();
            LerLivro(livroAux);
            AdicionarLivroNaBiblioteca(biblioteca, livroAux);
            break;
        case 2:
            scanf("%*[^A-Za-z]");
            scanf("%s", tituloAux);
            RemoverLivroDaBiblioteca(biblioteca, tituloAux);
            break;
        case 3:
            ListarLivrosDaBiblioteca(biblioteca);
            break;
        default:
            break;
        }
    }
    ApagaBiblioteca(biblioteca);

    return 0;
}