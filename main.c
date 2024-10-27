#include <stdio.h>
#include "ArvoreRN.h"
#include "ArvoreB.h"
#include "ArvoreAVL.h"

void visitar(int valor)
{
    printf("%d ", valor);
}

int main()
{
    ArvoreRN *a = criarRN();

    adicionarRN(a, 7);
    adicionarRN(a, 6);
    adicionarRN(a, 5);
    adicionarRN(a, 4);
    adicionarRN(a, 3);
    adicionarRN(a, 2);
    adicionarRN(a, 1);

    printf("In-order: ");
    percorrerProfundidadeInOrder(a, a->raiz, visitar);
    printf("\n");

    ArvoreB *arvore = criaArvoreB(1);

    // int contador = 0;

    adicionaChave(arvore, 12);
    adicionaChave(arvore, 3);
    adicionaChave(arvore, 5);
    adicionaChave(arvore, 7);
    adicionaChave(arvore, 15);
    adicionaChave(arvore, 99);
    adicionaChave(arvore, 1);

    percorreArvoreB(arvore->raiz);

    // printf("\nNúmero de operações: %d\n", contador);

    ArvoreAVL *avl = criarAVL();

    adicionarAVL(avl, 1);
    adicionarAVL(avl, 2);
    adicionarAVL(avl, 3);
    adicionarAVL(avl, 7);
    adicionarAVL(avl, 6);
    adicionarAVL(avl, 5);
    adicionarAVL(avl, 4);

    printf("In-order: ");
    percorrerAVL(avl->raiz, visitar);
    printf("\n");
}
