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
} AlunoCal;
AlunoCal alunoCal[MAX_ALUNOS];
void calcularNotaFinalCal(AlunoCal *alunoCal) {
    alunoCal->notaFinal = 0.2 * ((alunoCal->lista1 + alunoCal->lista2 + alunoCal->lista3)/3.0)+ 0.8 * ((alunoCal->prova1 + alunoCal->prova2 + alunoCal->prova3) / 2.0);
}

int estaAprovadoCal(AlunoCal alunoCal) {
    return alunoCal.notaFinal >= 6.0 && alunoCal.faltas < 16;
}

void imprimirAlunoCal(AlunoCal alunoCal) {
    printf("Matricula: %s\n", alunoCal.matricula);
    printf("Nome: %s\n", alunoCal.nome);
    printf("Faltas: %d\n", alunoCal.faltas);
    printf("Prova 1: %.2f\n", alunoCal.prova1);
    printf("Prova 2: %.2f\n", alunoCal.prova2);
    printf("Prova 3: %.2f\n", alunoCal.prova3);
    printf("Lista 1: %.2f\n", alunoCal.lista1);
    printf("Lista 2: %.2f\n", alunoCal.lista2);
    printf("Lista 3: %.2f\n", alunoCal.lista3);
    printf("Nota Final: %.2f\n", alunoCal.notaFinal);
    printf("Status: %s\n", estaAprovadoCal(alunoCal) ? "Aprovado" : "Reprovado");
}

void visualizarAlunoCal(AlunoCal alunoCal[], int numAlunosCal) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosCal; i++) {
        printf("%d - %s\n", i + 1, alunoCal[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja visualizar (de 1 a %d): ", numAlunosCal);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosCal) {
        printf("Índice inválido.\n");
        return;
    }
    imprimirAlunoCal(alunoCal[indice - 1]);
}

void editarAlunoCal(AlunoCal alunoCal[], int numAlunosCal) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosCal; i++) {
        printf("%d - %s\n", i + 1,alunoCal[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja editar (de 1 a %d): ", numAlunosCal);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosCal) {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para o índice do vetor (começa em 0)
    printf("Digite os novos dados do aluno %d:\n", indice + 1);
    printf("Faltas: ");
    scanf("%d", &alunoCal[indice].faltas);
    printf("Prova 1: ");
    scanf("%f", &alunoCal[indice].prova1);
    printf("Prova 2: ");
    scanf("%f", &alunoCal[indice].prova2);
    printf("Prova 3: ");
    scanf("%f", &alunoCal[indice].prova3);
    printf("Lista 1: ");
    scanf("%f", &alunoCal[indice].lista1);
    printf("Lista 2: ");
    scanf("%f", &alunoCal[indice].lista2);
    printf("Lista 3: ");
    scanf("%f", &alunoCal[indice].lista3);
    calcularNotaFinalCal(&alunoCal[indice]);
    printf("Dados do aluno %d editados com sucesso!\n", indice + 1);

    FILE *fileCal = fopen("calculo.txt", "r+");
  if (fileCal == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numAlunosCal; i++) {
        fprintf(fileCal, "%s %s %d %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", alunoCal[i].matricula, alunoCal[i].nome, alunoCal[i].faltas, alunoCal[i].prova1, alunoCal[i].prova2, alunoCal[i].prova3, alunoCal[i].lista1,alunoCal[i].lista2,alunoCal[i].lista3, alunoCal[i].notaFinal);
    }

    fclose(fileCal);
}
void funcaoFernandoCal(AlunoCal alunoCal[], int numAlunosCal) {
    int opcao;
    printf("Bem vindo(a), Fernando.\n");
    printf("Escolha uma opção:\n");
    printf("1 - Visualizar dados de um aluno\n");
    printf("2 - Editar dados de um aluno\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            visualizarAlunoCal(alunoCal, numAlunosCal);
            break;
        case 2:
            editarAlunoCal(alunoCal, numAlunosCal);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

