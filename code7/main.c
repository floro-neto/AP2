#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "fibonaci.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    int N;
  printf("Digite um n�mero inteiro\n");
  scanf("%d", &N);
  printf("O %d� termo da sequ�ncia de Fibonacci � %d\n", N, fibonacci(N));
  return 0;
}
