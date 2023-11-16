#include <stdlib.h>

typedef struct
{
    int *v;          // Vetor que representa a fila
    int N;           // Tamanho da fila
    int inicio, fim; // Indicadores de início e final da fila
} fila;

int enfileira(fila *f, int x)
{
    int proximo = (f->fim + 1) % f->N;
    if (proximo == f->inicio)
        return 0; // Fila cheia

    f->v[f->fim] = x;
    f->fim = proximo;
    return 1;
}

int desenfileira(fila *f, int *y)
{
    if (f->inicio == f->fim)
        return 0; // Fila vazia

    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    return 1;
}
