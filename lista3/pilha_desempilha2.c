#include <stdlib.h>

// Declaração da estrutura pilha
typedef struct pilha
{
    int *dados; // Vetor para armazenar os elementos da pilha
    int N;      // Capacidade total do vetor
    int topo;   // Indica a próxima posição livre na pilha
} pilha;

// Função para desempilhar um elemento
int desempilha(pilha *p, int *y)
{
    if (p->topo == 0)
    {
        // Pilha está vazia, não pode desempilhar
        return 0;
    }
    // Decrementa topo e salva o elemento removido em y
    p->topo--;
    *y = p->dados[p->topo];
    return 1; // Sucesso
}
