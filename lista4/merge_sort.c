#include <stdio.h>

void imprime(int *lista, int fim)
{
    for (int i = 0; i < fim; i++)
    {
        printf("%d", lista[i]);

        if (i != fim - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void merge(int *lista, int ini, int meio, int fim)
{
    int aux[fim - ini + 1];
    int i = ini, j = meio + 1, k = 0;

    while (i <= meio && j <= fim)
    {
        if (lista[i] < lista[j])
        {
            aux[k++] = lista[i++];
        }
        else
        {
            aux[k++] = lista[j++];
        }
    }

    while (i <= meio)
    {
        aux[k++] = lista[i++];
    }

    while (j <= fim)
    {
        aux[k++] = lista[j++];
    }

    for (i = ini, k = 0; i <= fim; i++, k++)
    {
        lista[i] = aux[k];
    }
}

void mergeSort(int *lista, int ini, int fim)
{
    if (ini < fim)
    {
        int meio = ini + (fim - ini) / 2;

        mergeSort(lista, ini, meio);
        mergeSort(lista, meio + 1, fim);

        merge(lista, ini, meio, fim);
    }
}

int main()
{
    int qtd;
    scanf("%d", &qtd);

    int lista[qtd];
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &lista[i]);
    }

    mergeSort(lista, 0, qtd - 1);

    imprime(lista, qtd);

    return 0;
}
