#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int matricula;
    char nome[50];
    char curso[50];
    float nota1;
    float nota2;
};

int main() {
    FILE *arquivo;
    struct Aluno aluno;

    arquivo = fopen("ALUNOS.DAT", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
}
