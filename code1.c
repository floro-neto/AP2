#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct data {
int dia;
int mes;
int ano;
};

struct ficha {
char nome[50];
char endereco[50];
char email[50];
int idade;
int cpf;
char sexo[50];
float altura;
float peso;
double imc;
};

int main()
{ setlocale(LC_ALL,"Portuguese");
    struct data data1;
    struct ficha ficha1;

    printf("Digite seu nome: \n");
    scanf("%s", ficha1.nome);
    fflush(stdin);
    printf("Digite seu endereço:\n");
    scanf("%s", ficha1.endereco);
     fflush(stdin);
    printf("Digite seu email:\n");
    scanf("%s", ficha1.email);
     fflush(stdin);
    printf("Digite sua idade:\n");
    scanf("%d", &ficha1.idade);
     fflush(stdin);
    printf("Digite seu cpf:\n");
    scanf("%d", &ficha1.cpf);
     fflush(stdin);
    printf("Digite seu sexo:\n");
    scanf("%s", ficha1.sexo);
     fflush(stdin);
    printf("Digite sua data de nascimento(dia mes ano):\n");
    scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);
     fflush(stdin);
    printf("Digite sua altura:\n");
    scanf("%f", &ficha1.altura);
     fflush(stdin);
    printf("Digite seu peso:\n");
    scanf("%f", &ficha1.peso);

    ficha1.imc = ficha1.peso / (ficha1.altura * ficha1.altura);
    printf("\n");

    printf("Nome: %s\n", ficha1.nome);
    printf("Endereço: %s\n", ficha1.endereco);
    printf("E-mail: %s\n", ficha1.email);
    printf("Idade: %d\n", ficha1.idade);
    printf("CPF: %d\n", ficha1.cpf);
    printf("Sexo: %s\n", ficha1.sexo);
    printf("Data de nascimento: %d%/%d/%d\n", data1.dia, data1.mes, data1.ano);
    printf("Altura: %.2f\n", ficha1.altura);
    printf("Peso: %.2f\n", ficha1.peso);
    printf("IMC: %.2f\n", ficha1.imc );

}
