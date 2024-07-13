#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 60
#define MAX_LENGTH 50

// Estrutura para armazenar os dados de um aluno
typedef struct {
    char matricula[10];
    char nome[20];
    int faltas;
   float prova1;
    float prova2;
    float prova3;
    float lista1;
    float lista2;
    float lista3;
    float notaFinal;
} AlunoGa;
AlunoGa alunoGa[MAX_ALUNOS];

void calcularNotaFinalGa(AlunoGa *alunoGa) {
    alunoGa->notaFinal = 0.2 * ((alunoGa->lista1 + alunoGa->lista2 + alunoGa->lista3)/3.0)+ 0.8 * ((alunoGa->prova1 + alunoGa->prova2 + alunoGa->prova3) / 3.0);
}

int estaAprovadoGa(AlunoGa alunoGa) {
    return alunoGa.notaFinal >= 6.0 && alunoGa.faltas < 16;
}

void imprimirAlunoGa(AlunoGa alunoGa) {
    printf("Matricula: %s\n", alunoGa.matricula);
    printf("Nome: %s\n", alunoGa.nome);
    printf("Faltas: %d\n", alunoGa.faltas);
    printf("Prova 1: %.2f\n", alunoGa.prova1);
    printf("Prova 2: %.2f\n", alunoGa.prova2);
    printf("Prova 3: %.2f\n", alunoGa.prova3);
    printf("Lista 1: %.2f\n", alunoGa.lista1);
    printf("Lista 2: %.2f\n", alunoGa.lista2);
    printf("Lista 3: %.2f\n", alunoGa.lista3);
    printf("Nota Final: %.2f\n", alunoGa.notaFinal);
    printf("Status: %s\n", estaAprovadoGa(alunoGa) ? "Aprovado" : "Reprovado");
}

void visualizarAlunoGa(AlunoGa alunoGa[], int numAlunosGa) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosGa; i++) {
        printf("%d - %s\n", i + 1, alunoGa[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja visualizar (de 1 a %d): ", numAlunosGa);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosGa) {
        printf("Índice inválido.\n");
        return;
    }
    imprimirAlunoGa(alunoGa[indice - 1]);
}

void editarAlunoGa(AlunoGa alunoGa[], int numAlunosGa) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosGa ; i++) {
        printf("%d - %s\n", i + 1, alunoGa[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja editar (de 1 a %d): ", numAlunosGa);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosGa) {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para o índice do vetor (começa em 0)
    printf("Digite os novos dados do aluno %d:\n", indice + 1);
    printf("Faltas: ");
    scanf("%d", &alunoGa[indice].faltas);
    printf("Prova 1: ");
    scanf("%f", &alunoGa[indice].prova1);
    printf("Prova 2: ");
    scanf("%f", &alunoGa[indice].prova2);
    printf("Prova 3: ");
    scanf("%f", &alunoGa[indice].prova3);
    printf("Lista 1: ");
    scanf("%f", &alunoGa[indice].lista1);
    printf("Lista 2: ");
    scanf("%f", &alunoGa[indice].lista2);
    printf("Lista 3: ");
    scanf("%f", &alunoGa[indice].lista3);
    calcularNotaFinalGa(&alunoGa[indice]);
    printf("Dados do aluno %d editados com sucesso!\n", indice + 1);

    FILE *fileGa = fopen("geoanalitica.txt", "r+");
  if (fileGa == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numAlunosGa; i++) {
        fprintf(fileGa, "%s %s %d %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", alunoGa[i].matricula, alunoGa[i].nome, alunoGa[i].faltas, alunoGa[i].prova1, alunoGa[i].prova2, alunoGa[i].prova3, alunoGa[i].lista1,alunoGa[i].lista2,alunoGa[i].lista3, alunoGa[i].notaFinal);
    }

    fclose(fileGa);
}

void funcaoFernandoGa(AlunoGa alunoGa[], int numAlunosGa) {
    int opcao;
    printf("Bem vindo(a), Fernando.\n");
    printf("Escolha uma opção:\n");
    printf("1 - Visualizar dados de um aluno\n");
    printf("2 - Editar dados de um aluno\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            visualizarAlunoGa(alunoGa, numAlunosGa);
            break;
        case 2:
            editarAlunoGa(alunoGa, numAlunosGa);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}


