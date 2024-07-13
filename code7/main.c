#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "fibonaci.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
    int N;
  printf("Digite um número inteiro\n");
  scanf("%d", &N);
  printf("O %dº termo da sequência de Fibonacci é %d\n", N, fibonacci(N));
  return 0;
}
