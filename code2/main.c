#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "rotina.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    int matriz[2][3];
    printf("Digite seis números inteiros separados por espaços para preencher a matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    substitui(matriz);
    printf("Matriz modificada:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
