#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    // Verifica se o vetor está cheio
    if (f->u == f->N)
    {
        int novoTamanho = f->N * 2;
        int *novoVetor = realloc(f->dados, novoTamanho * sizeof(int));
        if (novoVetor == NULL)
            return 0; // Falha ao alocar memória

        f->dados = novoVetor;
        f->N = novoTamanho;
    }

    // Insere o elemento
    f->dados[f->u] = x;
    f->u++;

    return 1;
}
