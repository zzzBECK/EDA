#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

// Função de busca iterativa
celula *busca(celula *le, int x)
{
    celula *p = le->prox; // Iniciando a partir do primeiro elemento após o nó cabeça
    while (p != NULL)
    {
        if (p->dado == x)
            return p; // Se encontrou o elemento, retorna o ponteiro para ele
        p = p->prox;
    }
    return NULL; // Se não encontrou, retorna NULL
}

// Função de busca recursiva
celula *busca_rec(celula *le, int x)
{
    if (le->prox == NULL)
        return NULL; // Se a lista terminou e não encontrou, retorna NULL
    if (le->prox->dado == x)
        return le->prox;           // Se encontrou o elemento, retorna o ponteiro para ele
    return busca_rec(le->prox, x); // Se não, chama a função recursivamente para o próximo elemento
}