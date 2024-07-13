#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "mediaAouP.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    double nota1,nota2,nota3;
    char tipo;
  printf("Digite as três notas de um aluno\n");
  scanf("%f %f %f", &nota1, &nota2, &nota3);
  printf("Digite o tipo de média: 'P' para ponderada ou 'A' para aritmética\n");
  scanf(" %c", &tipo);
  if (tipo == 'P' || tipo == 'p') {
    printf("A média ponderada do aluno é %.2lf\n", media_ponderada(nota1, nota2, nota3));
  } else if (tipo == 'A' || tipo == 'a') {
    printf("A média aritmética do aluno é %.2lf\n", media_aritmetica(nota1, nota2, nota3));
  } else {
    printf("Valor inválido\n");
  }
  return 0;
}
