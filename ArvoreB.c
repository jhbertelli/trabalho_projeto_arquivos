#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"

ArvoreB *criaArvoreB(int ordem)
{
    ArvoreB *a = malloc(sizeof(ArvoreB));
    a->ordem = ordem;
    a->raiz = criaNoB(a);

    return a;
}

int contador = 0;

NoB *criaNoB(ArvoreB *arvore)
{
    int max = arvore->ordem * 2;
    NoB *no = malloc(sizeof(NoB));

    no->pai = NULL;

    no->chaves = malloc(sizeof(int) * (max + 1));
    no->filhos = malloc(sizeof(NoB) * (max + 2));
    no->total = 0;

    for (int i = 0; i < max + 2; i++)
        no->filhos[i] = NULL;

    return no;
}

void percorreArvoreB(NoB *no)
{
    if (no != NULL)
    {
        for (int i = 0; i < no->total; i++)
        {
            percorreArvoreB(no->filhos[i]); // visita o filho a esquerda

            printf("%d ", no->chaves[i]);
        }

        percorreArvoreB(no->filhos[no->total]); // visita ultimo filho (direita)
    }
}

int pesquisaBinariaB(NoB *no, int chave)
{
    int inicio = 0, fim = no->total - 1, meio;

    while (inicio <= fim)
    {
        contador++;

        meio = (inicio + fim) / 2;

        if (no->chaves[meio] == chave)
        {
            return meio; // encontrou
        }
        else if (no->chaves[meio] > chave)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return inicio; // não encontrou
}

int localizaChave(ArvoreB *arvore, int chave)
{
    NoB *no = arvore->raiz;

    while (no != NULL)
    {
        int i = pesquisaBinariaB(no, chave);

        if (i < no->total && no->chaves[i] == chave)
        {
            return 1; // encontrou
        }
        else
        {
            no = no->filhos[i];
        }
    }

    return 0; // não encontrou
}

NoB *localizaNoB(ArvoreB *arvore, int chave)
{
    NoB *no = arvore->raiz;

    while (no != NULL)
    {
        contador++;

        int i = pesquisaBinariaB(no, chave);

        if (no->filhos[i] == NULL)
            return no; // encontrou nó
        else
            no = no->filhos[i];
    }

    return NULL; // não encontrou nenhum nó
}

void adicionaChaveNo(NoB *no, NoB *novo, int chave)
{
    int i = pesquisaBinariaB(no, chave);

    contador++;

    for (int j = no->total - 1; j >= i; j--)
    {
        no->chaves[j + 1] = no->chaves[j];
        no->filhos[j + 2] = no->filhos[j + 1];
    }

    no->chaves[i] = chave;
    no->filhos[i + 1] = novo;

    no->total++;
}

int transbordo(ArvoreB *arvore, NoB *no)
{
    contador++;

    return no->total > arvore->ordem * 2;
}

NoB *divideNo(ArvoreB *arvore, NoB *no)
{
    int meio = no->total / 2;
    NoB *novo = criaNoB(arvore);
    novo->pai = no->pai;

    contador++;

    for (int i = meio + 1; i < no->total; i++)
    {
        novo->filhos[novo->total] = no->filhos[i];
        novo->chaves[novo->total] = no->chaves[i];
        if (novo->filhos[novo->total] != NULL)
            novo->filhos[novo->total]->pai = novo;

        novo->total++;
    }

    novo->filhos[novo->total] = no->filhos[no->total];
    if (novo->filhos[novo->total] != NULL)
        novo->filhos[novo->total]->pai = novo;
    no->total = meio;
    return novo;
}

void adicionaChaveRecursivo(ArvoreB *arvore, NoB *no, NoB *novo, int chave)
{
    contador++;

    adicionaChaveNo(no, novo, chave);

    if (transbordo(arvore, no))
    {
        int promovido = no->chaves[arvore->ordem];
        NoB *novo = divideNo(arvore, no);

        if (no->pai == NULL)
        {
            contador++;

            NoB *pai = criaNoB(arvore);
            pai->filhos[0] = no;
            adicionaChaveNo(pai, novo, promovido);

            no->pai = pai;
            novo->pai = pai;
            arvore->raiz = pai;
        }
        else
            adicionaChaveRecursivo(arvore, no->pai, novo, promovido);
    }
}

void adicionaChave(ArvoreB *arvore, int chave)
{
    NoB *no = localizaNoB(arvore, chave);

    adicionaChaveRecursivo(arvore, no, NULL, chave);
}
