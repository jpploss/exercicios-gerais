#include "string_utils.h"
#include <stdio.h>
/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str) {
    int size = 0;
    while(str[size] != 0) {
        size++;
    }
    size++; // soma o '\0'
    return size;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest) {
    int i = 0;
    while(src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return;
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str) {
    int i = 0;
    int diff = 'A' - 'a';
    while(str[i] != 0) {
        if(str[i] >= 'a' && str[i] <= 'z') { // verifica se eh minúscula
            str[i] += diff;
        }
        i++;
    }
    return;
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str) {
    int i = 0;
    int diff = 'a' - 'A';
    while(str[i] != 0) {
        if(str[i] >= 'A' && str[i] <= 'Z') { // verifica se eh maiúscula
            str[i] += diff;
        }
        i++;
    }
    return;
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str) {
    int size = string_length(str) - 2; // tamanho da str desconsiderando o '\0' e contando a partir do 0
    int i;
    char aux;
    for(i = 0; i <= ((int)size/2); i++) {
        aux = str[i];
        str[i] = str[size - i];
        str[size - i] = aux;
    }
    return;
}