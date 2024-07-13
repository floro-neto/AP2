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
    float projetoFinal;
    float listas;
    float notaFinal;
} Aluno;
Aluno aluno[MAX_ALUNOS];

void calcularNotaFinal(Aluno *aluno) {
    aluno->notaFinal = 0.1 * aluno->listas + 0.9 * ((aluno->prova1 + aluno->prova2 + aluno->projetoFinal) / 3.0);
}

int estaAprovado(Aluno aluno) {
    return aluno.notaFinal >= 6.0 && aluno.faltas < 16;
}

void imprimirAluno(Aluno aluno) {
    printf("Matricula: %s\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Faltas: %d\n", aluno.faltas);
    printf("Prova 1: %.2f\n", aluno.prova1);
    printf("Prova 2: %.2f\n", aluno.prova2);
    printf("Projeto Final: %.2f\n", aluno.projetoFinal);
    printf("Listas: %.2f\n", aluno.listas);
    printf("Nota Final: %.2f\n", aluno.notaFinal);
    printf("Status: %s\n", estaAprovado(aluno) ? "Aprovado" : "Reprovado");
}

void visualizarAluno(Aluno aluno[], int numAlunos) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("%d - %s\n", i + 1, aluno[i].nome);
    }//loop para imprimir alunos disponiveis usando a variavel global numAlunos

    int indice;//usado para selecionar o aluno
    printf("Digite o índice do aluno que deseja visualizar (de 1 a %d): ", numAlunos);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunos) {
        printf("Índice inválido.\n");
        return;
    }
    imprimirAluno(aluno[indice - 1]);
}

void editarAluno(Aluno aluno[], int numAlunos) {
    printf("Lista de alunos disponíveis:\n");
    for (int i = 0; i < numAlunos ; i++) {
        printf("%d - %s\n", i + 1, aluno[i].nome);
    }//loop para imprimir alunos disponiveis usando a variavel global numAlunos

    int indice;
    printf("Digite o índice do aluno que deseja editar (de 1 a %d): ", numAlunos);
    scanf("%d", &indice);
    if (indice < 1 || indice > numAlunos) {
        printf("Índice inválido.\n");
        return;
    }
    indice--; // Ajustar para o índice do vetor (começa em 0)
    printf("Digite os novos dados do aluno %d:\n", indice + 1);
    printf("Faltas: ");
    scanf("%d", &aluno[indice].faltas);
    printf("Prova 1: ");
    scanf("%f", &aluno[indice].prova1);
    printf("Prova 2: ");
    scanf("%f", &aluno[indice].prova2);
    printf("Projeto Final: ");
    scanf("%f", &aluno[indice].projetoFinal);
    printf("Listas: ");
    scanf("%f", &aluno[indice].listas);
    calcularNotaFinal(&aluno[indice]);
    printf("Dados do aluno %d editados com sucesso!\n", indice + 1);

    FILE *file = fopen("AP2.txt", "r+");
  if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numAlunos; i++) {
        fprintf(file, "%s %s %d %.2f %.2f %.2f %.2f %.2f\n", aluno[i].matricula, aluno[i].nome, aluno[i].faltas, aluno[i].prova1, aluno[i].prova2, aluno[i].projetoFinal, aluno[i].listas, aluno[i].notaFinal);
    }//loop para salvar os dados em suas posições dentro do arquivo

    fclose(file);
}
//funcao usada para chamar no codigo principal
void funcaoAnaPaula(Aluno aluno[], int numAlunos) {
    int opcao;
    printf("Bem vindo(a), Ana Paula.\n");
    printf("Escolha uma opção:\n");
    printf("1 - Visualizar dados de um aluno\n");
    printf("2 - Editar dados de um aluno\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            visualizarAluno(aluno, numAlunos);
            break;
        case 2:
            editarAluno(aluno, numAlunos);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

