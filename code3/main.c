#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "elementos.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    int vetor[8];
    printf("Digite oito números inteiros separados por espaços: ");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &vetor[i]);
    }

    elementos(vetor);
    printf("Vetor modificado: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
