#include <stdio.h>

int checkGrowSort(int cards[])
{
    int i = 0;
    while (i < 4)
    {
        if (cards[i] > cards[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int checkDecreaseSort(int cards[])
{
    int i = 0;
    while (i < 4)
    {
        if (cards[i] < cards[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int cards[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &cards[i]);
    }

    if (checkGrowSort(cards))
        printf("C\n");
    else if (checkDecreaseSort(cards))
        printf("D\n");
    else
        printf("N\n");

    return 0;
}
