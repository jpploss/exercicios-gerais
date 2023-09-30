#include <stdio.h>
#include "calculadora.h"

float soma(float n1, float n2) {
    return n1 + n2;
}

float subtracao(float n1, float n2) {
    return n1 - n2;
}

float produto(float n1, float n2) {
    return n1 * n2;
}

float divisao(float n1, float n2) {
    return n1/n2;
}


int main() {
    char op = 0;
    float n1, n2;
    while(1) {
        scanf("%c", &op);
        if(op == 'f') break;

        scanf("%f %f", &n1, &n2);

        scanf("%*[^\n]");
        scanf("%*c");

        if(op == 'a') {
            printf("%.02f + %.02f = %0.2f\n", n1, n2, Calcular(n1, n2, soma));
        } else if(op == 's') {
            printf("%.02f - %.02f = %0.2f\n", n1, n2, Calcular(n1, n2, subtracao));
        } else if(op == 'm') {
            printf("%.02f x %.02f = %0.2f\n", n1, n2, Calcular(n1, n2, produto));
        } else if(op == 'd') {
            printf("%.02f / %.02f = %0.2f\n", n1, n2, Calcular(n1, n2, divisao));
        }
    }
    return 0;
}