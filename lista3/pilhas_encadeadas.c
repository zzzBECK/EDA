#include <stdlib.h>

// Definição da estrutura celula
typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

// Função para empilhar um elemento
void empilha(celula *p, int x)
{
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL)
    {
        // Falha na alocação de memória, você pode tratar esse caso conforme necessário
        return;
    }
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}

// Função para desempilhar um elemento
int desempilha(celula *p, int *y)
{
    if (p->prox == NULL)
    {
        // Pilha vazia, não pode desempilhar
        return 0;
    }
    celula *temp = p->prox;
    *y = temp->dado;
    p->prox = temp->prox;
    free(temp);
    return 1;
}
