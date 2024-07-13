#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 60
#define MAX_LENGTH 50

// Estrutura para armazenar os dados de um aluno
typedef struct {
    char matricula[10];
    char nome[20];
    int faltas;
    float presenca;
    float atividade;
    float prova1;
    float notaFinal;
} AlunoCVC;
AlunoCVC alunoCVC[MAX_ALUNOS];

void calcularNotaFinalCVC(AlunoCVC *alunoCVC) {
    alunoCVC->notaFinal = (alunoCVC->presenca + alunoCVC->atividade + alunoCVC->prova1) / 3.0;
}

int estaAprovadoCVC(AlunoCVC alunoCVC) {
    return alunoCVC.notaFinal >= 6.0 && alunoCVC.faltas < 16;
}

void imprimirAlunoCVC(AlunoCVC alunoCVC) {
    printf("Matricula: %s\n", alunoCVC.matricula);
    printf("Nome: %s\n", alunoCVC.nome);
    printf("Faltas: %d\n", alunoCVC.faltas);
    printf("Nota Presença: %.2f\n", alunoCVC.presenca);
    printf("Nota Atividades: %.2f\n", alunoCVC.atividade);
    printf("Prova 1: %.2f\n", alunoCVC.prova1);
    printf("Nota Final: %.2f\n", alunoCVC.notaFinal);
    printf("Status: %s\n", estaAprovadoCVC(alunoCVC) ? "Aprovado" : "Reprovado");
}

void visualizarAlunoCVC(AlunoCVC alunoCVC[], int numAlunosCVC) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosCVC; i++) {
        printf("%d - %s\n", i + 1, alunoCVC[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja visualizar (de 1 a %d): ", numAlunosCVC);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosCVC) {
        printf("Índice inválido.\n");
        return;
    }
    imprimirAlunoCVC(alunoCVC[indice - 1]);
}

void editarAlunoCVC(AlunoCVC alunoCVC[], int numAlunosCVC) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosCVC ; i++) {
        printf("%d - %s\n", i + 1, alunoCVC[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja editar (de 1 a %d): ", numAlunosCVC);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosCVC) {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para o índice do vetor (começa em 0)
    printf("Digite os novos dados do aluno %d:\n", indice + 1);
    printf("Faltas: ");
    scanf("%d", &alunoCVC[indice].faltas);
    printf("Presenca: ");
    scanf("%f", &alunoCVC[indice].presenca);
    printf("Atividades : ");
    scanf("%f", &alunoCVC[indice].atividade);
    printf("Prova 1: ");
    scanf("%f", &alunoCVC[indice].prova1);
    calcularNotaFinalCVC(&alunoCVC[indice]);
    printf("Dados do aluno %d editados com sucesso!\n", indice + 1);

    FILE *fileCVC = fopen("carvivencia.txt", "r+");
  if (fileCVC == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numAlunosCVC; i++) {
        fprintf(fileCVC, "%s %s %d %.2f %.2f %.2f %.2f\n", alunoCVC[i].matricula, alunoCVC[i].nome, alunoCVC[i].faltas, alunoCVC[i].presenca, alunoCVC[i].atividade, alunoCVC[i].prova1,alunoCVC[i].notaFinal);
    }

    fclose(fileCVC);
}

void funcaoJoslaineCVC(AlunoCVC alunoCVC[], int numAlunosCVC) {
    int opcao;
    printf("Bem vindo(a), Joslaine.\n");
    printf("Escolha uma opção:\n");
    printf("1 - Visualizar dados de um aluno\n");
    printf("2 - Editar dados de um aluno\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            visualizarAlunoCVC(alunoCVC, numAlunosCVC);
            break;
        case 2:
            editarAlunoCVC(alunoCVC, numAlunosCVC);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}


