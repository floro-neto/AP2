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
    float notaFinal;
} AlunoMD;
AlunoMD alunoMD[MAX_ALUNOS];

void calcularNotaFinalMD(AlunoMD *alunoMD) {
    alunoMD->notaFinal = (alunoMD->prova1 + alunoMD->prova2 + alunoMD->prova3) / 3.0;
}

int estaAprovadoMD(AlunoMD alunoMD) {
    return alunoMD.notaFinal >= 6.0 && alunoMD.faltas < 16;
}

void imprimirAlunoMD(AlunoMD alunoMD) {
    printf("Matricula: %s\n", alunoMD.matricula);
    printf("Nome: %s\n", alunoMD.nome);
    printf("Faltas: %d\n", alunoMD.faltas);
    printf("Prova 1: %.2f\n", alunoMD.prova1);
    printf("Prova 2: %.2f\n", alunoMD.prova2);
    printf("Prova 3: %.2f\n", alunoMD.prova3);
    printf("Nota Final: %.2f\n", alunoMD.notaFinal);
    printf("Status: %s\n", estaAprovadoMD(alunoMD) ? "Aprovado" : "Reprovado");
}

void visualizarAlunoMD(AlunoMD alunoMD[], int numAlunosMD) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosMD; i++) {
        printf("%d - %s\n", i + 1, alunoMD[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja visualizar (de 1 a %d): ", numAlunosMD);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosMD) {
        printf("Índice inválido.\n");
        return;
    }
    imprimirAlunoMD(alunoMD[indice - 1]);
}

void editarAlunoMD(AlunoMD alunoMD[], int numAlunosMD) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosMD ; i++) {
        printf("%d - %s\n", i + 1, alunoMD[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja editar (de 1 a %d): ", numAlunosMD);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosMD) {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para o índice do vetor (começa em 0)
    printf("Digite os novos dados do aluno %d:\n", indice + 1);
    printf("Faltas: ");
    scanf("%d", &alunoMD[indice].faltas);
    printf("Prova 1: ");
    scanf("%f", &alunoMD[indice].prova1);
    printf("Prova 2 : ");
    scanf("%f", &alunoMD[indice].prova2);
    printf("Prova 3: ");
    scanf("%f", &alunoMD[indice].prova3);
    calcularNotaFinalMD(&alunoMD[indice]);
    printf("Dados do aluno %d editados com sucesso!\n", indice + 1);

    FILE *fileMD = fopen("mddados.txt", "r+");
  if (fileMD == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numAlunosMD; i++) {
        fprintf(fileMD, "%s %s %d %.2f %.2f %.2f %.2f\n", alunoMD[i].matricula, alunoMD[i].nome, alunoMD[i].faltas, alunoMD[i].prova1, alunoMD[i].prova2, alunoMD[i].prova3,alunoMD[i].notaFinal);
    }

    fclose(fileMD);
}

void funcaoJoslaineMD(AlunoMD alunoMD[], int numAlunosMD) {
    int opcao;
    printf("Bem vindo(a), Joslaine.\n");
    printf("Escolha uma opção:\n");
    printf("1 - Visualizar dados de um aluno\n");
    printf("2 - Editar dados de um aluno\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            visualizarAlunoMD(alunoMD, numAlunosMD);
            break;
        case 2:
            editarAlunoMD(alunoMD, numAlunosMD);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}



