#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArvoreAVL.h"
#include "ArvoreRN.h"
#include "ArvoreB.h"

#define NUM_CONJUNTOS 10
#define MAX_CHAVES 10000

int main()
{
    int numeros[NUM_CONJUNTOS][MAX_CHAVES];

    // semente para numeros aleatórios
    srand(0);

    for (int i = 0; i < NUM_CONJUNTOS; i++)
        for (int j = 0; j < MAX_CHAVES; j++)
            numeros[i][j] = (rand() % 10000) + 1;  // gera um numero aleatorio entre 1 e 10000

    // arquivo para enviar os resultados das quantidades de operações
    FILE *fp = fopen("resultados.txt", "w");

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo de resultados!\n");
        return 1;
    }

    ArvoreAVL *arvoreAVL = criarAVL();

    fprintf(fp, "%s", "Adição AVL\n");
    // adição - AVL
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            adicionarAVL(arvoreAVL, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    ArvoreB *arvoreB1 = criaArvoreB(1);

    // adição - B (ordem 1)
    fprintf(fp, "%s", "Adição B1\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            adicionaChaveB(arvoreB1, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    ArvoreB *arvoreB5 = criaArvoreB(5);

    // adição - B (ordem 5)
    fprintf(fp, "%s", "Adição B5\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            adicionaChaveB(arvoreB5, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    ArvoreB *arvoreB10 = criaArvoreB(10);

    // adição - B (ordem 10)
    fprintf(fp, "%s", "Adição B10\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            adicionaChaveB(arvoreB10, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    ArvoreRN *arvoreRN = criarRN();

    // adição - RN
    fprintf(fp, "%s", "Adição RN\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            adicionarRN(arvoreRN, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    // remoção - AVL
    fprintf(fp, "%s", "Remoção AVL\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            removerAVL(arvoreAVL, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

   // remoção - B (ordem 1)
    fprintf(fp, "%s", "Remoção B1\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            removerChaveB(arvoreB1, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    // remoção - B (ordem 5)
    fprintf(fp, "%s", "Remoção B5\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            removerChaveB(arvoreB5, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    // remoção - B (ordem 10)
    fprintf(fp, "%s", "Remoção B10\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            removerChaveB(arvoreB10, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    // remoção - RN
    fprintf(fp, "%s", "Remoção RN\n");
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            removerRN(arvoreRN, numeros[i][j], &qtdOperacoes);
        
        fprintf(fp, "%d\n", qtdOperacoes);
    }

    fclose(fp);

    printf("Contagem de operações feita com sucesso.\nAbra o arquivo resultados.txt para visualizar os resultados.\n");
}