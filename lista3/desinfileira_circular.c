#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y)
{
    // Verificar se a fila está vazia
    if (f->p == f->u)
    {
        return 0;
    }

    // Desenfileirar (remover o elemento da frente da fila)
    *y = f->dados[f->p];

    // Atualizar o ponteiro da frente da fila
    f->p = (f->p + 1) % f->N;

    return 1;
}
