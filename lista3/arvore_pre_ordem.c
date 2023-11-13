#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void pre_ordem(no *raiz)
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
            // Encontre o nó predecessor (o nó mais à direita na subárvore esquerda)
            no *predecessor = atual->esq;
            while (predecessor->dir != NULL && predecessor->dir != atual)
            {
                predecessor = predecessor->dir;
            }

            if (predecessor->dir == NULL)
            {
                // Estabeleça a ligação para o nó atual e imprima antes de ir para a esquerda
                predecessor->dir = atual;
                printf("%d ", atual->dado);
                atual = atual->esq;
            }
            else
            {
                // Restaure a árvore original antes de seguir para a direita
                predecessor->dir = NULL;
                atual = atual->dir;
            }
        }
    }
}