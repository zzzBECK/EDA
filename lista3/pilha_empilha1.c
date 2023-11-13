#include <stdlib.h>

// Declaração da estrutura celula
typedef struct celula
{
    int dado;            // Valor armazenado na célula
    struct celula *prox; // Ponteiro para a próxima célula
} celula;

// Função para empilhar um elemento
int empilha(celula *p, int x)
{
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL)
    {
        // Falha na alocação de memória, retorna 0
        return 0;
    }
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
    return 1; // Sucesso
}
