/*
    Alunos:
    Chloe Anne Scaramal - 12311BSI232
    João Vitor Serra - 12311BSI254
    Samira Rodrigues Silva - 12311BSI203
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int torre[3][5];

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i, j, mov, rtn, status = 0, *pa = 0, *pb = 0, *pc = 0;

/*  mov: movimento a realizar, rtn = retorno se o movimento é válido
    status: se a torre foi completa
    pa/b/c: ponteiros que apontam pro primeiro disco de cada torre */


    // Definir a torre inicial
    for(i = 0; i < 5; i++) torre[0][i] = i + 1;

    // Laço de repetição em que o jogo acontece
    while(status == 0){

        // Os próximos 3 'for' acham o primeiro disco da torre e atribuem sua posição ou NULL ao ponteiro correspondente
        for(i = 0; i < 5; i++){
            if (torre[0][i] != 0){
                pa = &torre[0][i];
                break;
            } else pa = NULL;
        }
        for(i = 0; i < 5; i++){
            if (torre[1][i] != 0){
                pb = &torre[1][i];
                break;
            } else pb = NULL;
        }

        for(i = 0; i < 5; i++){
            if (torre[2][i] != 0){
                pc = &torre[2][i];
                break;
            } else pc = NULL;
        }

        // Imprimir a torre
        printf("\nTorre de Hanói\n----------------\nA  B  C\n-  -  -\n");
        for(i = 0; i < 5; i++){ 
            for(j = 0; j < 3; j++){
                if(torre[j][i] == 0) printf("|  ");
                else printf("%d  ", torre[j][i]);
            }
            printf("\n");
        }

        // Imprimir o menu do jogo
        printf("\nMovimentos:\n\n");

        printf("Mover de A para B: 1\nMover de A para C: 2\nMover de B para C: 3\nMover de B para A: 4\nMover de C para B: 5\nMover de C para A: 6\nDesistir: 0");

        printf("\nDigite o movimento para realizar: ");
        scanf("%d", &mov); getchar();

        // Realizar o movimento caso seja válido, ou encerrar caso desista
        rtn = 0;

        if(mov == 1 && pa != NULL){
            if(pb == NULL){
                pb = &torre[1][4];
                *pb = *pa;
                *pa = 0;
            } else if(pb != NULL && *pa < *pb){
                *(pb-1) = *pa;
                *pa = 0;
            } else rtn = 1;
        } else if(mov == 2 && pa != NULL){
            if(pc == NULL){
                pc = &torre[2][4];
                *pc = *pa;
                *pa = 0;
            } else if(pc != NULL && *pa < *pc){
                *(pc-1) = *pa;
                *pa = 0;
            } else rtn = 1;
        } else if(mov == 3 && pb != NULL){
            if(pc == NULL){
                pc = &torre[2][4];
                *pc = *pb;
                *pb = 0;
            } else if(pc != NULL && *pb < *pc){
                *(pc-1) = *pb;
                *pb = 0;
            } else rtn = 1;
        } else if(mov == 4 && pb != NULL){
            if(pa == NULL){
                pa = &torre[0][4];
                *pa = *pb;
                *pb = 0;
            } else if(pa != NULL && *pb < *pa){
                *(pa - 1) = *pb;
                *pb = 0;
            } else rtn = 1;
        } else if(mov == 5 && pc != NULL){
            if(pb == NULL){
                pb = &torre[1][4];
                *pb = *pc;
                *pc = 0;
            } else if(pb != NULL && *pc < *pb){
                *(pb - 1) = *pc;
                *pc = 0;
            } else rtn = 1;
        } else if(mov == 6 && pc != NULL){
            if(pa == NULL){
                pa = &torre[0][4];
                *pa = *pc;
                *pc = 0;
            } else if(pa != NULL && *pc < *pa){
                *(pa - 1) = *pc;
                *pc = 0;
            } else rtn = 1;
        } else if(mov == 0){
            printf("Até a próxima!\n");
            return 0;
        } else rtn = 1;

        if(rtn == 1) printf("\nMovimento inválido!\nTente novamente.\n");

        if(torre[1][0] == 1 || torre[2][0] == 1) status = 1;
    }

    printf("\nTorre de Hanói\n----------------\nA  B  C\n-  -  -\n");
    for(i = 0; i < 5; i++){ 
        for(j = 0; j < 3; j++){
            if(torre[j][i] == 0) printf("|  ");
            else printf("%d  ", torre[j][i]);
        }
        printf("\n");
    }

    printf("\nParabéns! Você concluiu a torre de Hanói.\n\n");

    return 0;
}