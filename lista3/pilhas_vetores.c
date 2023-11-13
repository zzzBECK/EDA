#include <stdlib.h>

// Definição da estrutura da pilha
typedef struct
{
    int *v;   // Vetor que contém os elementos da pilha
    int N;    // Tamanho de v
    int topo; // Indicador do topo da pilha
} pilha;

// Função para empilhar um elemento
void empilha(pilha *p, int x)
{
    if (p->topo == p->N)
    { // Verifica se a pilha está cheia
        // Dobrar o tamanho da pilha
        p->N *= 2;
        p->v = realloc(p->v, p->N * sizeof(int));
    }
    // Empilha o elemento
    p->v[p->topo] = x;
    p->topo++;
}

// Função para desempilhar um elemento
int desempilha(pilha *p, int *y)
{
    if (p->topo == 0)
    {
        // Pilha está vazia, não pode desempilhar
        return 0;
    }
    // Desempilha o elemento
    p->topo--;
    *y = p->v[p->topo];
    return 1;
}
