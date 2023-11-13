#include <stdlib.h>

// Declaração da estrutura celula
typedef struct celula
{
    int dado;            // Valor armazenado na célula
    struct celula *prox; // Ponteiro para a próxima célula
} celula;

// Função para desempilhar um elemento
int desempilha(celula *p, int *y)
{
    if (p->prox == NULL)
    {
        // Pilha está vazia, não pode desempilhar
        return 0;
    }
    celula *temp = p->prox; // Célula a ser removida
    *y = temp->dado;        // Salva o dado da célula removida
    p->prox = temp->prox;   // Atualiza o ponteiro do nó cabeça
    free(temp);             // Libera a memória da célula removida
    return 1;               // Sucesso
}
