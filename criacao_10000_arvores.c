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


    // adição - AVL
    for (int i = 0; i < 1; i++)
    {
        double tempo_total_avl;

        for (int quant_chaves = 1; quant_chaves <= MAX_CHAVES; quant_chaves++)
        {
            ArvoreAVL *arvoreAVL = criarAVL();

            clock_t inicio = clock();

            for (int j = 0; j < quant_chaves; j++)
                adicionarAVL(arvoreAVL, numeros[i][j]);

            double tempo_percorrido = (double)(clock() - inicio)/CLOCKS_PER_SEC;
            
            printf("AVL #%d - %lf\n", quant_chaves, tempo_percorrido);
        }

        printf("%lf\n", tempo_total_avl);
    }
}