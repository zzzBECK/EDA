#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Mover os elementos de arr[0..i-1], que são maiores que key,
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[50000]; // Array para armazenar até 50000 elementos
    int n = 0;
    int num;

    // Lendo números até o fim do arquivo (EOF)
    while (scanf("%d", &num) != EOF)
    {
        arr[n++] = num;
        if (n >= 50000)
        {
            break; // Evita ler mais de 50000 elementos
        }
    }

    // Ordenando o array
    insertionSort(arr, n);

    // Imprimindo o array ordenado
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
