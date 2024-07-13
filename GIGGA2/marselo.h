#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 60
#define MAX_LENGTH 50

// Estrutura para armazenar os dados de um aluno
typedef struct {
    char matricula[20];
    char nome[20];
    int faltas;
    float prova1;
    float prova2;
    float projeto1;
    float projeto2;
    float projeto3;
    float projeto4;
    float projeto5;
    float NPresenca;
    float notaFinal;
} AlunoSD;
AlunoSD alunoSD[MAX_ALUNOS];

void calcularNotaFinalSD(AlunoSD *alunoSD) {
     float N1 = (alunoSD->prova1 + alunoSD->prova2) / 2.0;
    float N2 = (alunoSD->projeto1 + alunoSD->projeto2 + alunoSD->projeto3 + alunoSD->projeto4 + alunoSD->projeto5 + alunoSD->NPresenca) / 6.0;
    alunoSD->notaFinal = (N1 + N2) / 2.0;
}
int estaAprovadoSD(AlunoSD alunoSD) {
    return alunoSD.notaFinal >= 6.0 && alunoSD.faltas < 16;
}

void imprimirAlunoSD(AlunoSD alunoSD) {
    printf("Matricula: %s\n", alunoSD.matricula);
    printf("Nome: %s\n", alunoSD.nome);
    printf("Faltas: %d\n", alunoSD.faltas);
    printf("Prova 1: %.2f\n", alunoSD.prova1);
    printf("Prova 2: %.2f\n", alunoSD.prova2);
    printf("Projeto 1: %.2f\n", alunoSD.projeto1);
    printf("Projeto 2: %.2f\n", alunoSD.projeto2);
    printf("Projeto 3: %.2f\n", alunoSD.projeto3);
    printf("Projeto 4: %.2f\n", alunoSD.projeto4);
    printf("Projeto 5: %.2f\n", alunoSD.projeto5);
    printf("Nota presença: %.2f\n", alunoSD.NPresenca);
    printf("Nota Final: %.2f\n", alunoSD.notaFinal);
    printf("Status: %s\n", estaAprovadoSD(alunoSD) ? "Aprovado" : "Reprovado");
}

void visualizarAlunoSD(AlunoSD alunoSD[], int numAlunosSD) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosSD; i++) {
        printf("%d - %s\n", i + 1, alunoSD[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja visualizar (de 1 a %d): ", numAlunosSD);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosSD) {
        printf("Índice inválido.\n");
        return;
    }
    imprimirAlunoSD(alunoSD[indice - 1]);
}

void editarAlunoSD(AlunoSD alunoSD[], int numAlunosSD) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunosSD ; i++) {
        printf("%d - %s\n", i + 1, alunoSD[i].nome);
    }

    int indice;
    printf("Digite o índice do aluno que deseja editar (de 1 a %d): ", numAlunosSD);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunosSD) {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para o índice do vetor (começa em 0)
    printf("Digite os novos dados do aluno %d:\n", indice + 1);
    printf("Faltas: ");
    scanf("%d", &alunoSD[indice].faltas);
    printf("Prova 1: ");
    scanf("%f", &alunoSD[indice].prova1);
    printf("Prova 2: ");
    scanf("%f", &alunoSD[indice].prova2);
    printf("Projeto 1: ");
    scanf("%f", &alunoSD[indice].projeto1);
    printf("Projeto 2: ");
    scanf("%f", &alunoSD[indice].projeto2);
    printf("Projeto 3: ");
    scanf("%f", &alunoSD[indice].projeto3);
    printf("Projeto 4: ");
    scanf("%f", &alunoSD[indice].projeto4);
    printf("Projeto 5: ");
    scanf("%f", &alunoSD[indice].projeto5);
    printf("Nota presenca: ");
    scanf("%f", &alunoSD[indice].NPresenca);
    calcularNotaFinalSD(&alunoSD[indice]);
    printf("Dados do aluno %d editados com sucesso!\n", indice + 1);

    FILE *fileSD = fopen("marselodados.txt", "r+");
  if (fileSD == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numAlunosSD; i++) {
        fprintf(fileSD, "%s %s %d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", alunoSD[i].matricula, alunoSD[i].nome, alunoSD[i].faltas, alunoSD[i].prova1, alunoSD[i].prova2, alunoSD[i].projeto1, alunoSD[i].projeto2, alunoSD[i].projeto3, alunoSD[i].projeto4, alunoSD[i].projeto5, alunoSD[i].NPresenca, alunoSD[i].notaFinal);
    }

    fclose(fileSD);
}

void funcaoMarselo(AlunoSD alunoSD[], int numAlunosSD) {
    int opcao;
    printf("Bem vindo(a), Marselo.\n");
    printf("Escolha uma opção:\n");
    printf("1 - Visualizar dados de um aluno\n");
    printf("2 - Editar dados de um aluno\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            visualizarAlunoSD(alunoSD, numAlunosSD);
            break;
        case 2:
            editarAlunoSD(alunoSD, numAlunosSD);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}


