#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int numAlunos = 0;
int numAlunosCal = 0;
int numAlunosGa = 0;
int numAlunosCVC = 0;
int numAlunosMD = 0;
int numAlunosSD =  0;
#include "Algoritimos.h"
#include "calculo.h"
#include "GeoA.h"
#include "Carvivencia.h"
#include "matdiscreta.h"
#include "marselo.h"
#include "mostradadosa.h"

#define MAX_MATRICULA_LENGTH 20
#define MAX_SENHA_LENGTH 20
#define MAX_NOME_LENGTH 50

// função para verificar se uma matrícula está presente no arquivo "matriculas.txt" e retornar o nome correspondente
char *obterNomePorMatricula(const char *matricula) {
    FILE *arquivoMatriculas = fopen("matriculas.txt", "r");
    FILE *arquivoNomes = fopen("nomes.txt", "r");
    if (arquivoMatriculas == NULL || arquivoNomes == NULL) {
        printf("Erro ao abrir o arquivo de matrículas ou nomes.\n");
        exit(1);
    }

    char matriculaArquivo[MAX_MATRICULA_LENGTH];
    char nome[MAX_NOME_LENGTH];
    //loop para ler linha por linha do arquivo
    while (fgets(matriculaArquivo, sizeof(matriculaArquivo), arquivoMatriculas) != NULL) {
        // remover o caractere de nova linha '\n' do final de cada matrícula no arquivo
        //para caso atingir o limite ou encontrar "\n"
        matriculaArquivo[strcspn(matriculaArquivo, "\n")] = '\0';

        if (strcmp(matricula, matriculaArquivo) == 0) {
            // se a matrícula corresponder, ler e retornar o nome correspondente
            //usa sizeof para ler todo a variavel e seu tamanho max [MAX_NOME_LENGTH] para detro do buffer(memoria temporaria)
            fgets(nome, sizeof(nome), arquivoNomes);
            // remover o caractere de nova linha '\n' do final do nome quando encontrado
            nome[strcspn(nome, "\n")] = '\0';
            //prepara para fechar pois achou matricula
            fclose(arquivoMatriculas);
            fclose(arquivoNomes);
            return strdup(nome); // retorna uma cópia alocada dinamicamente do nome encontrado
        }

        // se a matrícula não corresponder, ler e descartar o próximo nome
        fgets(nome, sizeof(nome), arquivoNomes);
    }

    fclose(arquivoMatriculas);
    fclose(arquivoNomes);
    return NULL; // matrícula não encontrada
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    char matricula[MAX_MATRICULA_LENGTH];
    char senha[MAX_SENHA_LENGTH];
    int opcao;
//abrir file ap2
 FILE *file = fopen("AP2.txt", "r+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo AP2.txt para leitura.\n");
        return 1;
    }

//loop para ler o arquivo e aumentar a variavel numAlunos para determinar a quantidade de linhas/alunos
      while (fscanf(file, "%s %s %d %f %f %f %f %f\n", aluno[numAlunos].matricula, aluno[numAlunos].nome, &aluno[numAlunos].faltas, &aluno[numAlunos].prova1, &aluno[numAlunos].prova2, &aluno[numAlunos].projetoFinal, &aluno[numAlunos].listas, &aluno[numAlunos].notaFinal) == 8) {
    calcularNotaFinal(&aluno[numAlunos]);
    numAlunos++;
}

    fclose(file);
//abrir file calculo2
 FILE *fileCal = fopen("calculo.txt", "r+");
    if (fileCal == NULL) {
        printf("Erro ao abrir o arquivo calculo.txt para leitura.\n");
        return 1;
    }

    while (fscanf(fileCal, "%s %s %d %f %f %f %f %f %f %f\n", alunoCal[numAlunosCal].matricula, alunoCal[numAlunosCal].nome, &alunoCal[numAlunosCal].faltas, &alunoCal[numAlunosCal].prova1, &alunoCal[numAlunosCal].prova2, &alunoCal[numAlunosCal].prova3, &alunoCal[numAlunosCal].lista1,&alunoCal[numAlunosCal].lista2,&alunoCal[numAlunosCal].lista3, &alunoCal[numAlunosCal].notaFinal) == 10) {
    calcularNotaFinalCal(&alunoCal[numAlunosCal]);
    numAlunosCal++;
}

    fclose(fileCal);
//abrir file geo analitica

FILE *fileGa = fopen("geoanalitica.txt", "r+");
    if (fileGa == NULL) {
        printf("Erro ao abrir o arquivo calculo.txt para leitura.\n");
        return 1;
    }


    while (fscanf(fileGa, "%s %s %d %f %f %f %f %f %f %f\n", alunoGa[numAlunosGa].matricula, alunoGa[numAlunosGa].nome, &alunoGa[numAlunosGa].faltas, &alunoGa[numAlunosGa].prova1, &alunoGa[numAlunosGa].prova2, &alunoGa[numAlunosGa].prova3, &alunoGa[numAlunosGa].lista1,&alunoGa[numAlunosGa].lista2,&alunoGa[numAlunosGa].lista3, &alunoGa[numAlunosGa].notaFinal) == 10){
    calcularNotaFinalGa(&alunoGa[numAlunosGa]);
    numAlunosGa++;
}

    fclose(fileGa);
//abrir file Carreira e vivencia

FILE *fileCVC = fopen("carvivencia.txt", "r+");
    if (fileCVC == NULL) {
        printf("Erro ao abrir o arquivo calculo.txt para leitura.\n");
        return 1;
    }


    while (fscanf(fileCVC, "%s %s %d %f %f %f %f \n", alunoCVC[numAlunosCVC].matricula, alunoCVC[numAlunosCVC].nome, &alunoCVC[numAlunosCVC].faltas, &alunoCVC[numAlunosCVC].presenca, &alunoCVC[numAlunosCVC].atividade, &alunoCVC[numAlunosCVC].prova1, &alunoCVC[numAlunosCVC].notaFinal) == 7){
    calcularNotaFinalCVC(&alunoCVC[numAlunosCVC]);
    numAlunosCVC++;
}

    fclose(fileCVC);
//abrir file matematica dicreta
FILE *fileMD = fopen("mddados.txt", "r+");
    if (fileMD == NULL) {
        printf("Erro ao abrir o arquivo calculo.txt para leitura.\n");
        return 1;
    }

   while (fscanf(fileMD, "%s %s %d %f %f %f %f \n", alunoMD[numAlunosMD].matricula, alunoMD[numAlunosMD].nome, &alunoMD[numAlunosMD].faltas, &alunoMD[numAlunosMD].prova1, &alunoMD[numAlunosMD].prova2, &alunoMD[numAlunosMD].prova3, &alunoMD[numAlunosMD].notaFinal) == 7){
    calcularNotaFinalMD(&alunoMD[numAlunosMD]);
    numAlunosMD++;
}

    fclose(fileMD);
//abrir file marselo(Sistemas Digitais)
FILE *fileSD = fopen("marselodados.txt", "r+");
    if (fileSD == NULL) {
        printf("Erro ao abrir o arquivo calculo.txt para leitura.\n");
        return 1;
    }

while (fscanf(fileSD, "%s %s %d %f %f %f %f %f %f %f %f %f\n", alunoSD[numAlunosSD].matricula, alunoSD[numAlunosSD].nome, &alunoSD[numAlunosSD].faltas, &alunoSD[numAlunosSD].prova1, &alunoSD[numAlunosSD].prova2, &alunoSD[numAlunosSD].projeto1,&alunoSD[numAlunosSD].projeto2,&alunoSD[numAlunosSD].projeto3,&alunoSD[numAlunosSD].projeto4,&alunoSD[numAlunosSD].projeto5,&alunoSD[numAlunosSD].NPresenca, &alunoSD[numAlunosSD].notaFinal) == 12) {
    calcularNotaFinalSD(&alunoSD[numAlunosSD]);
    numAlunosSD++;
}

    fclose(fileSD);
     printf("Bem-vindo ao sistema de login.\n");
     printf("\n\n");
    printf("   GGGGGG    IIIII   GGGGGG   GGGGGG    AAAAA    \n");
    printf("  GGG        III    GGG      GGG       A     A   \n");
    printf("  GGG GGG    III    GGG GGG  GGG GGG   AAAAAAA   \n");
    printf("   GGGGGG    IIIII   GGGGGG   GGGGGG   A     A   \n\n");
    printf("Caso seja aluno, insira sua matrícula:\n ");
    printf("Caso seja professor apenas aperte enter\n");
    //comando que recebe matricula para comparação
    fgets(matricula, sizeof(matricula), stdin);
    matricula[strcspn(matricula, "\n")] = '\0'; // remover o caractere de nova linha '\n' do final

    // verificar se a matrícula está presente no arquivo de matrículas
   char *nomeAluno = obterNomePorMatricula(matricula);
        if (nomeAluno != NULL) {
    printf("Login de aluno realizado com sucesso!\n");
    printf("\nAluno logado: %s\n\n", nomeAluno);
    free(nomeAluno); // liberar a memória alocada dinamicamente(nome encontrado)

    printf("Escolha a disciplina para visualisar suas notas:\n");
    printf("1. Algoritmos e Programação II\n");
    printf("2. Cálculo II\n");
    printf("3. Geometria Analítica\n");
    printf("4. Carreira e Vivência na Computação\n");
    printf("5. Matemática Discreta\n");
    printf("6. Sistemas Digitais\n");
    printf("Opção: ");
    scanf("%d", &opcao);
//case para opção alunos
    switch (opcao) {
        //case ap2
        case 1:
            printf("Disciplina selecionada: Algoritmos e Programação II\n");
            mostrarDadosAluno(aluno, numAlunos, matricula);
            break;
        case 2:
            //case cal
            printf("Disciplina selecionada: Cálculo II\n");
            mostrarDadosAlunoCal(alunoCal, numAlunosCal, matricula);
            break;
        case 3:
            //case ga
            printf("Disciplina selecionada: Geometria Analítica\n");
            mostrarDadosAlunoGa(alunoGa, numAlunosGa, matricula);
            break;
        case 4:
            //case cvc
            printf("Disciplina selecionada: Carreira e Vivência na Computação\n");
            mostrarDadosAlunoCVC(alunoCVC, numAlunosCVC, matricula);
            break;
        case 5:
            //case md
            printf("Disciplina selecionada: Matemática Discreta\n");
           mostrarDadosAlunoMD(alunoMD, numAlunosMD, matricula);
            break;
        case 6:
            //case sd
            printf("Disciplina selecionada: Sistemas Digitais\n");
           mostrarDadosAlunoSD(alunoSD, numAlunosSD, matricula);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
    } else {
        //caso seja professor
        printf("Você é um professor.\n");
        printf("Por favor, escolha sua opção:\n");
        printf("1. Ana Paula\n");//senha 1234
        printf("2. Fernando\n");//senha 2356
        printf("3. Joslaine\n");//senha 3456
        printf("4. Marcelo\n");// senha 4567
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // consumir o caractere de nova linha pendente do buffer de entrada(remove o \n ao pressionar enter)

        // login dos professores com senha e opção de disciplina
        switch (opcao) {
            case 1:
                //case Ana Paula
                printf("Insira a senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0'; // remover o caractere de nova linha '\n' do final
                if (strcmp(senha, "1234") == 0) {
                    printf("Login realizado com sucesso para Ana Paula!\n");
                    printf("Escolha a disciplina:\n");
                    printf("1. Algoritmos e Programação II\n");
                    printf("Opção: ");
                    scanf("%d", &opcao);
                    if (opcao != 1) {
                        printf("Opção inválida.\n");
                        return 1;
                    }
                    printf("Disciplina selecionada: Algoritmos e Programação II\n");
    funcaoAnaPaula(aluno, numAlunos);

                } else {
                    printf("Senha incorreta.\n");
                }
                break;
            case 2:
                //case Fernando
                printf("Insira a senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0'; // remover o caractere de nova linha '\n' do final
                if (strcmp(senha, "2345") == 0) {
                    printf("Login realizado com sucesso para Fernando!\n");
                    printf("Escolha a disciplina:\n");
                    printf("1. Cálculo II\n");
                    printf("2. Geometria Analítica\n");
                    printf("Opção: ");
                    scanf("%d", &opcao);
                    if (opcao == 1) {
                            //funcao caso seja calculo
                             printf("Disciplina selecionada: Cálculo II\n");
                        funcaoFernandoCal(alunoCal, numAlunosCal);
                    } else if (opcao == 2) {
                        //funcao caso seja GA
                         printf("Disciplina selecionada: Geometria Analítica\n");
                        funcaoFernandoGa(alunoGa, numAlunosGa);
                    } else {
                    printf("Opção inválida.\n");
                        return 1;
                        }
                            } else {
                            printf("Senha incorreta.\n");
                        }
                break;
            case 3:
                //case Joslaine
                printf("Insira a senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0'; // remover o caractere de nova linha '\n' do final
                if (strcmp(senha, "3456") == 0) {
                    printf("Login realizado com sucesso para Joslaine!\n");
                    printf("Escolha a disciplina:\n");
                    printf("1. Carreira e Vivência na Computação\n");
                    printf("2. Matemática Discreta\n");
                    printf("Opção: ");
                    scanf("%d", &opcao);
                  if (opcao == 1) {
                        //funcao caso seja CVC
                             printf("Disciplina selecionada: Carreira e Vivência na Computação\n");
                       funcaoJoslaineCVC(alunoCVC, numAlunosCVC);
                    } else if (opcao == 2) {
                        //funcao caso seja MD
                        printf("Disciplina selecionada: Matemática Discreta\n");
                        funcaoJoslaineMD(alunoMD, numAlunosMD);
                    } else {
                    printf("Opção inválida.\n");
                        return 1;
                        }
                            } else {
                            printf("Senha incorreta.\n");
                        }
                break;
            case 4:
                //case Marcelo
                printf("Insira a senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0'; // remover o caractere de nova linha '\n' do final
                if (strcmp(senha, "4567") == 0) {
                    printf("Login realizado com sucesso para Marcelo!\n");
                    printf("Escolha a disciplina:\n");
                    printf("1. Sistemas Digitais\n");
                    printf("Opção: ");
                    scanf("%d", &opcao);
                    if (opcao != 1) {
                        printf("Opção inválida.\n");
                        return 1;
                    }
                    //funcao caso seja SD
                    printf("Disciplina selecionada: Sistemas Digitais\n");
                    funcaoMarselo(alunoSD, numAlunosSD);
                } else {
                    printf("Senha incorreta.\n");
                }
                break;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
