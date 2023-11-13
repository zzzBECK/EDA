#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void inverterEstrada(no *inicio, no *fim)
{
    if (inicio == fim)
        return;
    no *x = inicio;
    no *y = inicio->dir;
    no *z;

    while (x != fim)
    {
        z = y->dir;
        y->dir = x;
        x = y;
        y = z;
    }
}

void imprimeReverso(no *inicio, no *fim)
{
    inverterEstrada(inicio, fim);
    no *p = fim;
    while (1)
    {
        printf("%d ", p->dado);
        if (p == inicio)
            break;
        p = p->dir;
    }
    inverterEstrada(fim, inicio);
}

void pos_ordem(no *raiz)
{
    no *dummy = (no *)malloc(sizeof(no));
    dummy->esq = raiz;
    raiz = dummy;

    while (raiz != NULL)
    {
        if (raiz->esq == NULL)
        {
            raiz = raiz->dir;
        }
        else
        {
            no *predecessor = raiz->esq;
            while (predecessor->dir != NULL && predecessor->dir != raiz)
            {
                predecessor = predecessor->dir;
            }

            if (predecessor->dir == NULL)
            {
                predecessor->dir = raiz;
                raiz = raiz->esq;
            }
            else
            {
                imprimeReverso(raiz->esq, predecessor);
                predecessor->dir = NULL;
                raiz = raiz->dir;
            }
        }
    }

    free(dummy);
}