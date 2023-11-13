#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz)
{
    no *atual = raiz;

    while (atual != NULL)
    {
        if (atual->esq == NULL)
        {
            printf("%d ", atual->dado);
            atual = atual->dir;
        }
        else
        {
            // Encontre o predecessor (o nó mais à direita na subárvore esquerda)
            no *predecessor = atual->esq;
            while (predecessor->dir != NULL && predecessor->dir != atual)
            {
                predecessor = predecessor->dir;
            }

            if (predecessor->dir == NULL)
            {
                // Estabeleça a ligação para o nó atual
                predecessor->dir = atual;
                atual = atual->esq;
            }
            else
            {
                // Restaure a árvore original e imprima o nó atual
                predecessor->dir = NULL;
                printf("%d ", atual->dado);
                atual = atual->dir;
            }
        }
    }
}