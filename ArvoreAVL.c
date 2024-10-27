#include <stdlib.h>
#include <stdio.h>
#include "ArvoreAVL.h"

int max(int a, int b)
{
    return a > b ? a : b;
}

ArvoreAVL *criarAVL()
{
    ArvoreAVL *arvore = malloc(sizeof(ArvoreAVL));
    arvore->raiz = NULL;

    return arvore;
}

int vaziaAVL(ArvoreAVL *arvore)
{
    return arvore->raiz == NULL;
}

void adicionarAVL(ArvoreAVL *arvore, int valor)
{
    NoAVL *no = arvore->raiz;

    while (no != NULL)
    {
        if (valor > no->valor)
        {
            if (no->direita != NULL)
            {
                no = no->direita;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (no->esquerda != NULL)
            {
                no = no->esquerda;
            }
            else
            {
                break;
            }
        }
    }

    printf("Adicionando %d\n", valor);
    NoAVL *novo = malloc(sizeof(NoAVL));
    novo->valor = valor;
    novo->pai = no;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->altura = 1;

    if (no == NULL)
    {
        arvore->raiz = novo;
    }
    else
    {
        if (valor > no->valor)
        {
            no->direita = novo;
        }
        else
        {
            no->esquerda = novo;
        }

        balanceamentoAVL(arvore, no);
    }
}

NoAVL *localizarAVL(NoAVL *no, int valor)
{
    while (no != NULL)
    {
        if (no->valor == valor)
        {
            return no;
        }

        no = valor < no->valor ? no->esquerda : no->direita;
    }

    return NULL;
}

void percorrerAVL(NoAVL *no, void (*callback)(int))
{
    if (no != NULL)
    {
        percorrerAVL(no->esquerda, callback);
        callback(no->valor);
        percorrerAVL(no->direita, callback);
    }
}

void balanceamentoAVL(ArvoreAVL *arvore, NoAVL *no)
{
    while (no != NULL)
    {
        no->altura = max(alturaAVL(no->esquerda), alturaAVL(no->direita)) + 1;
        int fator = fb(no);

        if (fator > 1)
        { // árvore mais pesada para esquerda
            // rotação para a direita
            if (fb(no->esquerda) > 0)
            {
                printf("RSD(%d)\n", no->valor);
                rsd(arvore, no); // rotação simples a direita, pois o FB do filho tem sinal igual
            }
            else
            {
                printf("RDD(%d)\n", no->valor);
                rdd(arvore, no); // rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        }
        else if (fator < -1)
        { // árvore mais pesada para a direita
            // rotação para a esquerda
            if (fb(no->direita) < 0)
            {
                printf("RSE(%d)\n", no->valor);
                rse(arvore, no); // rotação simples a esquerda, pois o FB do filho tem sinal igual
            }
            else
            {
                printf("RDE(%d)\n", no->valor);
                rde(arvore, no); // rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai;
    }
}

int alturaAVL(NoAVL *no)
{
    return no != NULL ? no->altura : 0;
}

int fb(NoAVL *no)
{
    int esquerda = 0, direita = 0;

    if (no->esquerda != NULL)
    {
        esquerda = no->esquerda->altura;
    }

    if (no->direita != NULL)
    {
        direita = no->direita->altura;
    }

    return esquerda - direita;
}

NoAVL *rse(ArvoreAVL *arvore, NoAVL *no)
{
    NoAVL *pai = no->pai;
    NoAVL *direita = no->direita;

    if (direita->esquerda != NULL)
    {
        direita->esquerda->pai = no;
    }

    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL)
    {
        arvore->raiz = direita;
    }
    else
    {
        if (pai->esquerda == no)
        {
            pai->esquerda = direita;
        }
        else
        {
            pai->direita = direita;
        }
    }

    no->altura = max(alturaAVL(no->esquerda), alturaAVL(no->direita)) + 1;
    direita->altura = max(alturaAVL(direita->esquerda), alturaAVL(direita->direita)) + 1;

    return direita;
}

NoAVL *rsd(ArvoreAVL *arvore, NoAVL *no)
{
    NoAVL *pai = no->pai;
    NoAVL *esquerda = no->esquerda;

    if (esquerda->direita != NULL)
    {
        esquerda->direita->pai = no;
    }

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL)
    {
        arvore->raiz = esquerda;
    }
    else
    {
        if (pai->esquerda == no)
        {
            pai->esquerda = esquerda;
        }
        else
        {
            pai->direita = esquerda;
        }
    }

    no->altura = max(alturaAVL(no->esquerda), alturaAVL(no->direita)) + 1;
    esquerda->altura = max(alturaAVL(esquerda->esquerda), alturaAVL(esquerda->direita)) + 1;

    return esquerda;
}

NoAVL *rde(ArvoreAVL *arvore, NoAVL *no)
{
    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

NoAVL *rdd(ArvoreAVL *arvore, NoAVL *no)
{
    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}
