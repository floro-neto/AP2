#include <stdio.h>

typedef struct {
    int matricula;
    float notas[3];
} Aluno;

Aluno Turma[5];

void LeAluno(int index);
void ImprimeTurma();
float CalculaMediaAluno(int index);

int main() {
    int i;
    for (i = 0; i < 5; i++) {
        LeAluno(i);
    }

    ImprimeTurma();

    for (i = 0; i < 5; i++) {
        float media = CalculaMediaAluno(i);
        printf("Aluno %d - Media = %f\n", i + 1, media);
    }

    return 0;
}

void LeAluno(int index) {
    printf("Digite a matricula do aluno %d: ", index + 1);
    scanf("%d", &Turma[index].matricula);

    printf("Digite as notas do aluno %d (3 notas separadas por espaços): ", index + 1);
    for (int i = 0; i < 3; i++) {
        scanf("%f", &Turma[index].notas[i]);
    }
}

void ImprimeTurma() {
    printf("\nDados da Turma:\n");
    for (int i = 0; i < 5; i++) {
        printf("Aluno %d - Matricula: %d, Notas: %.2f %.2f %.2f\n",
               i + 1, Turma[i].matricula, Turma[i].notas[0], Turma[i].notas[1], Turma[i].notas[2]);
    }
}

float CalculaMediaAluno(int index) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += Turma[index].notas[i];
    }
    return soma / 3.0;
}
