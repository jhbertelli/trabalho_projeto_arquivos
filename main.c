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

    ArvoreAVL *arvoreAVL = criarAVL();

    // adição - AVL
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            adicionarAVL(arvoreAVL, numeros[i][j], &qtdOperacoes);
        
        printf("Adição AVL #%d - %d\n", i + 1, qtdOperacoes);
    }

    // remoção - AVL
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            removerAVL(arvoreAVL, numeros[i][j], &qtdOperacoes);
        
        printf("Remoção AVL #%d - %d\n", i + 1, qtdOperacoes);
    }

    ArvoreB *arvoreB1 = criaArvoreB(1);

    // adição - B (ordem 1)
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            // TODO: contar operações
            adicionaChaveB(arvoreB1, numeros[i][j], &qtdOperacoes);
        
        printf("Adição B1 #%d - %d\n", i + 1, qtdOperacoes);
    }

    ArvoreB *arvoreB5 = criaArvoreB(5);

    // adição - B (ordem 5)
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            // TODO: contar operações
            adicionaChaveB(arvoreB5, numeros[i][j], &qtdOperacoes);
        
        printf("Adição B5 #%d - %d\n", i + 1, qtdOperacoes);
    }

    ArvoreB *arvoreB10 = criaArvoreB(10);

    // adição - B (ordem 10)
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            // TODO: contar operações
            adicionaChaveB(arvoreB10, numeros[i][j], &qtdOperacoes);
        
        printf("Adição B10 #%d - %d\n", i + 1, qtdOperacoes);
    }

    ArvoreRN *arvoreRN = criarRN();

    // adição - RN
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        int qtdOperacoes = 0;

        for (int j = 0; j < MAX_CHAVES; j++)
            // TODO: contar operações
            adicionarRN(arvoreRN, numeros[i][j], &qtdOperacoes);
        
        printf("Adição RN #%d - %d\n", i + 1, qtdOperacoes);
    }

    // TODO: remoção das árvores: B e RN
}