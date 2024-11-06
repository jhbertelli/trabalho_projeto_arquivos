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

    // Semente para numeros aleatórios
    srand(time(0));


    for (int i = 0; i < NUM_CONJUNTOS; i++)
        for (int j = 0; j < MAX_CHAVES; j++)
            numeros[i][j] = (rand() % 10000) + 1;  // Gera um numero aleatorio entre 1 e 10000

    ArvoreAVL *arvoreAVL = criarAVL();

    // adição - AVL
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        double tempo_total_avl;

        for (int j = 0; j < MAX_CHAVES; j++)
        {
            clock_t inicio = clock();

            adicionarAVL(arvoreAVL, numeros[i][j]);

            double tempo_percorrido = (double)(clock() - inicio)/CLOCKS_PER_SEC;
            
            tempo_total_avl += tempo_percorrido;

            // printf("%d - %lf\n", j, tempo_percorrido);
        }
        
        printf("AVL #%d - %lf\n", i, tempo_total_avl);
    }

    ArvoreB *arvoreB1 = criaArvoreB(1);

    // adição - B (ordem 1)
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        double tempo_total_B;

        for (int j = 0; j < MAX_CHAVES; j++)
        {
            clock_t inicio = clock();

            adicionaChave(arvoreB1, numeros[i][j]);

            double tempo_percorrido = (double)(clock() - inicio)/CLOCKS_PER_SEC;
            
            tempo_total_B += tempo_percorrido;

            // printf("%d - %lf\n", j, tempo_percorrido);
        }
        
        printf("B1 #%d - %lf\n", i, tempo_total_B);
    }

    ArvoreB *arvoreB5 = criaArvoreB(5);

    // adição - B (ordem 5)
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        double tempo_total_B;

        for (int j = 0; j < MAX_CHAVES; j++)
        {
            clock_t inicio = clock();

            adicionaChave(arvoreB5, numeros[i][j]);

            double tempo_percorrido = (double)(clock() - inicio)/CLOCKS_PER_SEC;
            
            tempo_total_B += tempo_percorrido;

            // printf("%d - %lf\n", j, tempo_percorrido);
        }
        
        printf("B5 #%d - %lf\n", i, tempo_total_B);
    }

    ArvoreB *arvoreB10 = criaArvoreB(10);

    // adição - B (ordem 10)
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        double tempo_total_B;

        for (int j = 0; j < MAX_CHAVES; j++)
        {
            clock_t inicio = clock();

            adicionaChave(arvoreB10, numeros[i][j]);

            double tempo_percorrido = (double)(clock() - inicio)/CLOCKS_PER_SEC;
            
            tempo_total_B += tempo_percorrido;

            // printf("%d - %lf\n", j, tempo_percorrido);
        }
        
        printf("B10 #%d - %lf\n", i, tempo_total_B);
    }

    ArvoreRN *arvoreRN = criarRN();

    // adição - RN
    for (int i = 0; i < NUM_CONJUNTOS; i++)
    {
        double tempo_total_RN;

        for (int j = 0; j < MAX_CHAVES; j++)
        {
            clock_t inicio = clock();

            adicionarRN(arvoreRN, numeros[i][j]);

            double tempo_percorrido = (double)(clock() - inicio)/CLOCKS_PER_SEC;
            
            tempo_total_RN += tempo_percorrido;

            // printf("%d - %lf\n", j, tempo_percorrido);
        }
        
        printf("RN #%d - %lf\n", i, tempo_total_RN);
    }

}