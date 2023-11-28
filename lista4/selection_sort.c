#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;

    // Mover a fronteira do subarray não ordenado
    for (i = 0; i < n - 1; i++)
    {
        // Encontrar o menor elemento no subarray não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Trocar o menor elemento encontrado com o primeiro elemento
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[1000]; // Array para armazenar até 1000 elementos
    int n = 0;
    int num;

    // Lendo números até o fim do arquivo (EOF)
    while (scanf("%d", &num) != EOF)
    {
        arr[n++] = num;
        if (n >= 1000)
        {
            break; // Evita ler mais de 1000 elementos
        }
    }

    // Ordenando o array
    selectionSort(arr, n);

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
