#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2)
{

    if (l->prox == NULL)
    {
        l1->prox = NULL;
        l2->prox = NULL;
        return;
    }

    else if (l->prox->dado % 2 != 0)
    {
        l1->prox = l->prox;
        divide_lista(l->prox, l1->prox, l2);
    }
    else
    {
        l2->prox = l->prox;
        divide_lista(l->prox, l1, l2->prox);
    }
}