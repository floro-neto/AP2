#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "mediaAouP.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    double nota1,nota2,nota3;
    char tipo;
  printf("Digite as tr�s notas de um aluno\n");
  scanf("%f %f %f", &nota1, &nota2, &nota3);
  printf("Digite o tipo de m�dia: 'P' para ponderada ou 'A' para aritm�tica\n");
  scanf(" %c", &tipo);
  if (tipo == 'P' || tipo == 'p') {
    printf("A m�dia ponderada do aluno � %.2lf\n", media_ponderada(nota1, nota2, nota3));
  } else if (tipo == 'A' || tipo == 'a') {
    printf("A m�dia aritm�tica do aluno � %.2lf\n", media_aritmetica(nota1, nota2, nota3));
  } else {
    printf("Valor inv�lido\n");
  }
  return 0;
}
