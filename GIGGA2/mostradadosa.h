#include <stdio.h>
#include <stdlib.h>
//funções dos alunos:
//função para imprimir os dados do aluno selecionado usando variavel matricula do codigo main
void mostrarDadosAluno(const Aluno alunos[], int numAlunos, const char *matricula) {
    int encontrado = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (strcmp(alunos[i].matricula, matricula) == 0) {
            printf("Matrícula: %s\n", alunos[i].matricula);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Faltas: %d\n", alunos[i].faltas);
            printf("Nota da Prova 1: %.2f\n", alunos[i].prova1);
            printf("Nota da Prova 2: %.2f\n", alunos[i].prova2);
            printf("Nota do Projeto Final: %.2f\n", alunos[i].projetoFinal);
            printf("Nota das Listas: %.2f\n", alunos[i].listas);
            printf("Nota Final: %.2f\n", alunos[i].notaFinal);
             printf("Status: %s\n", estaAprovado(alunos[i]) ? "Aprovado" : "Reprovado");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}

void mostrarDadosAlunoCal(const AlunoCal alunosCal[], int numAlunosCal, const char *matricula) {
    int encontrado = 0;
    for (int i = 0; i < numAlunosCal; i++) {
        if (strcmp(alunosCal[i].matricula, matricula) == 0) {
    printf("Matricula: %s\n", alunoCal[i].matricula);
    printf("Nome: %s\n", alunoCal[i].nome);
    printf("Faltas: %d\n", alunoCal[i].faltas);
    printf("Prova 1: %.2f\n", alunoCal[i].prova1);
    printf("Prova 2: %.2f\n", alunoCal[i].prova2);
    printf("Prova 3: %.2f\n", alunoCal[i].prova3);
    printf("Lista 1: %.2f\n", alunoCal[i].lista1);
    printf("Lista 2: %.2f\n", alunoCal[i].lista2);
    printf("Lista 3: %.2f\n", alunoCal[i].lista3);
    printf("Nota Final: %.2f\n", alunoCal[i].notaFinal);
    printf("Status: %s\n", estaAprovadoCal(alunosCal[i]) ? "Aprovado" : "Reprovado");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}

void mostrarDadosAlunoGa(const AlunoGa alunosGa[], int numAlunosGa, const char *matricula) {
    int encontrado = 0;
    for (int i = 0; i < numAlunosGa; i++) {
        if (strcmp(alunosGa[i].matricula, matricula) == 0) {
           printf("Matricula: %s\n", alunoGa[i].matricula);
    printf("Nome: %s\n", alunoGa[i].nome);
    printf("Faltas: %d\n", alunoGa[i].faltas);
    printf("Prova 1: %.2f\n", alunoGa[i].prova1);
    printf("Prova 2: %.2f\n", alunoGa[i].prova2);
    printf("Prova 3: %.2f\n", alunoGa[i].prova3);
    printf("Lista 1: %.2f\n", alunoGa[i].lista1);
    printf("Lista 2: %.2f\n", alunoGa[i].lista2);
    printf("Lista 3: %.2f\n", alunoGa[i].lista3);
    printf("Nota Final: %.2f\n", alunoGa[i].notaFinal);
    printf("Status: %s\n", estaAprovadoGa(alunosGa[i]) ? "Aprovado" : "Reprovado");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}

void mostrarDadosAlunoCVC(const AlunoCVC alunosCVC[], int numAlunosCVC, const char *matricula) {
    int encontrado = 0;
    for (int i = 0; i < numAlunosCVC; i++) {
        if (strcmp(alunosCVC[i].matricula, matricula) == 0) {
    printf("Matricula: %s\n", alunoCVC[i].matricula);
    printf("Nome: %s\n", alunoCVC[i].nome);
    printf("Faltas: %d\n", alunoCVC[i].faltas);
    printf("Nota Presença: %.2f\n", alunoCVC[i].presenca);
    printf("Nota Atividades: %.2f\n", alunoCVC[i].atividade);
    printf("Prova 1: %.2f\n", alunoCVC[i].prova1);
    printf("Nota Final: %.2f\n", alunoCVC[i].notaFinal);
    printf("Status: %s\n", estaAprovadoCVC(alunosCVC[i]) ? "Aprovado" : "Reprovado");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}

void mostrarDadosAlunoMD(const AlunoMD alunosMD[], int numAlunosMD, const char *matricula) {
    int encontrado = 0;
    for (int i = 0; i < numAlunosMD; i++) {
        if (strcmp(alunosMD[i].matricula, matricula) == 0) {
    printf("Matricula: %s\n", alunoMD[i].matricula);
    printf("Nome: %s\n", alunoMD[i].nome);
    printf("Faltas: %d\n", alunoMD[i].faltas);
    printf("Prova 1: %.2f\n", alunoMD[i].prova1);
    printf("Prova 2: %.2f\n", alunoMD[i].prova2);
    printf("Prova 3: %.2f\n", alunoMD[i].prova3);
    printf("Nota Final: %.2f\n", alunoMD[i].notaFinal);
    printf("Status: %s\n", estaAprovadoMD(alunosMD[i]) ? "Aprovado" : "Reprovado");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}

void mostrarDadosAlunoSD(const AlunoSD alunosSD[], int numAlunosSD, const char *matricula) {
    int encontrado = 0;
    for (int i = 0; i < numAlunosSD; i++) {
        if (strcmp(alunosSD[i].matricula, matricula) == 0) {
    printf("Matricula: %s\n", alunoSD[i].matricula);
    printf("Nome: %s\n", alunoSD[i].nome);
    printf("Faltas: %d\n", alunoSD[i].faltas);
    printf("Prova 1: %.2f\n", alunoSD[i].prova1);
    printf("Prova 2: %.2f\n", alunoSD[i].prova2);
    printf("Projeto 1: %.2f\n", alunoSD[i].projeto1);
    printf("Projeto 2: %.2f\n", alunoSD[i].projeto2);
    printf("Projeto 3: %.2f\n", alunoSD[i].projeto3);
    printf("Projeto 4: %.2f\n", alunoSD[i].projeto4);
    printf("Projeto 5: %.2f\n", alunoSD[i].projeto5);
    printf("Nota presença: %.2f\n", alunoSD[i].NPresenca);
    printf("Nota Final: %.2f\n", alunoSD[i].notaFinal);
    printf("Status: %s\n", estaAprovadoSD(alunosSD[i]) ? "Aprovado" : "Reprovado");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado.\n");
    }
}
