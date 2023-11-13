#include <stdlib.h>

// Declaração da estrutura pilha
typedef struct pilha
{
    int *dados; // Vetor para armazenar os elementos da pilha
    int N;      // Capacidade total do vetor
    int topo;   // Indica a próxima posição livre na pilha
} pilha;

// Função para empilhar um elemento
int empilha(pilha *p, int x)
{
    if (p->topo == p->N)
    { // Verifica se a pilha está cheia
        // Tentativa de redimensionar o vetor
        int novaCapacidade = p->N == 0 ? 1 : p->N * 2;
        int *novoVetor = realloc(p->dados, novaCapacidade * sizeof(int));
        if (novoVetor == NULL)
        {
            // Falha ao redimensionar, retorna 0
            return 0;
        }
        p->dados = novoVetor;
        p->N = novaCapacidade;
    }
    // Insere o elemento na posição topo e incrementa topo
    p->dados[p->topo] = x;
    p->topo++;
    return 1; // Sucesso
}
