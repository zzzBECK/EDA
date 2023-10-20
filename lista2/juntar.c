#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_recursivo(celula *l1, celula *l2, celula **l3_atual)
{
    if (l1 == NULL)
    {
        *l3_atual = l2; // se l1 está vazio, adiciona o restante de l2 à l3
        return;
    }

    if (l2 == NULL)
    {
        *l3_atual = l1; // se l2 está vazio, adiciona o restante de l1 à l3
        return;
    }

    // Escolhe o nó com o menor valor e avança o ponteiro correspondente
    if (l1->dado < l2->dado)
    {
        *l3_atual = l1;
        mescla_recursivo(l1->prox, l2, &((*l3_atual)->prox));
    }
    else
    {
        *l3_atual = l2;
        mescla_recursivo(l1, l2->prox, &((*l3_atual)->prox));
    }
}

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    // Chama a função recursiva
    mescla_recursivo(l1->prox, l2->prox, &(l3->prox));
}
