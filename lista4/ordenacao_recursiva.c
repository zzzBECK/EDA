#include <stdio.h>

// Função recursiva para ordenação por inserção
void ordenaPorInsercao(int *v, int n)
{
    // Caso base: se há 1 ou nenhum elemento, está ordenado
    if (n <= 1)
        return;

    // Ordena os primeiros n-1 elementos
    ordenaPorInsercao(v, n - 1);

    // Insere o último elemento na posição correta
    int ultimo = v[n - 1];
    int j = n - 2;

    // Move os elementos maiores que o último para frente
    while (j >= 0 && v[j] > ultimo)
    {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = ultimo;
}

void ordena(int *v, int n)
{
    ordenaPorInsercao(v, n);
}
