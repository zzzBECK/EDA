#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y)
{
    // Verificar se a fila está vazia
    if (f->prox == f)
    {
        return 0;
    }

    celula *temp = f->prox;

    *y = temp->dado;

    f->prox = temp->prox;

    free(temp);

    return 1;
}