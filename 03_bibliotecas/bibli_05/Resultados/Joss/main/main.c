#include <stdio.h>
#include "string_utils.h"

int PrintAndReadMenu();

int main() {
    int op = 0;
    char word[1001];
    scanf("%[^\n]", word);

    while(op != 6) {
        op = PrintAndReadMenu();;
        switch (op)
        {
        case 1:
            printf("Tamanho da string: %d\n\n", string_length(word));
            break;
        case 2:
            string_copy(word, word);
            printf("String copiada: %s\n\n", word);
            break;
        case 3:
            string_upper(word);
            printf("String convertida para maiusculas: %s\n\n", word);
            break;
        case 4:
            string_lower(word);
            printf("String convertida para minusculas: %s\n\n", word);
            break;
        case 5:
            string_reverse(word);
            printf("String invertida: \n%s\n\n", word);
            break;
        case 6:
            break;
        }
    }

    return 0;
}


int PrintAndReadMenu() {
    int option;
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
    scanf("%d", &option);
    printf("\n");
    return option;
}

