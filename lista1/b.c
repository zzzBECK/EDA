#include <stdio.h>

int main()
{

    int L, D, K, P, totalValue = 0;

    scanf("%d %d %d %d", &L, &D, &K, &P);

    totalValue += ((int)(L) / D * P) + (L * K);

    printf("%d\n", totalValue);

    return 0;
}