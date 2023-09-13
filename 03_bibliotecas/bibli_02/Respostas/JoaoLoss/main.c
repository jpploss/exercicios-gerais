#include <stdio.h>
#include "matrix_utils.h"
#include <stdlib.h>

int PrintAndReadMenu();

int main() {
    int l1, c1;
    scanf("%d%d", &l1, &c1);
    int mat1[l1][c1];
    matrix_read(l1, c1, mat1);

    int l2, c2;
    scanf("%d%d", &l2, &c2);
    int mat2[l2][c2];
    matrix_read(l2, c2, mat2);
    
    int option = 0;
    int transpMat2[c2][l2];
    int transpMat1[c1][l1];
    int sumESub[l1][c1];
    int multiplyMat[l1][c2];
    int scalar, matChosen;

    while(!(option == 6)) {
        option = PrintAndReadMenu();

        switch (option)
        {
        case 1:
            if(possible_matrix_sum(l1, c1, l2, c2)) {
                matrix_add(l1, c1, mat1, l2, c2, mat2, sumESub);
                matrix_print(l1, c1, sumESub);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 2:
            if(possible_matrix_sub(l1, c1, l2, c2)) {
                matrix_sub(l1, c1, mat1, l2, c2, mat2, sumESub);
                matrix_print(l1, c1, sumESub);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 3:
            if(possible_matrix_multiply(c1, l2)) {
                matrix_multiply(l1, c1, mat1, l2, c2, mat2, multiplyMat);
                matrix_print(l1, c2, multiplyMat);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
            break;
        case 4:
            scanf("%d%d", &scalar, &matChosen);
            if(matChosen == 1) {
                scalar_multiply(l1, c1, mat1, scalar);
                matrix_print(l1, c1, mat1);
            } else if(matChosen == 2) {
                scalar_multiply(l2, c2, mat2, scalar);
                matrix_print(l2, c2, mat2);
            }
            break;
        case 5:
            transpose_matrix(l1, c1, mat1, transpMat1);
            matrix_print(c1, l1, transpMat1);
            printf("\n");

            transpose_matrix(l2, c2, mat2, transpMat2);
            matrix_print(c2, l2, transpMat2);
            break;
        case 6:
            break;   
        default:
            break;         
        }
    }

    return 0;
}

int PrintAndReadMenu() {
    int option;
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
    scanf("%d", &option);
    printf("\n");
    return option;
}