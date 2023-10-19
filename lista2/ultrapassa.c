#include <stdio.h>

void ultrapassa(int list[], int n, int index, int limit, int currentSum)
{
    if (index == n)
        return; // caso base: fim da lista

    currentSum += list[index];

    if (currentSum > limit)
    {
        ultrapassa(list, n, index + 1, limit, 0); // resetamos a soma acumulada
        printf("%d\n", list[index]);
    }
    else
    {
        ultrapassa(list, n, index + 1, limit, currentSum); // mantemos a soma acumulada
    }
}

int main()
{
    int list[100], limit;
    int i = 0;

    scanf("%d", &list[i]);

    while (list[i] != 0)
    {
        i++;
        scanf("%d", &list[i]);
    }

    scanf("%d", &limit);

    ultrapassa(list, i, 0, limit, 0);

    return 0;
}
