#include <stdio.h>

void trocaXY(char *str)
{
    if (*str == '\0')
        return;

    if (*str == 'x')
    {
        printf("y");
        trocaXY(str + 1);
    }
    else
    {
        printf("%c", *str);
        trocaXY(str + 1);
    }
}

int main(int argc, char const *argv[])
{
    char str[1001];

    scanf("%[^\n]", str);

    trocaXY(str);
    printf("\n");

    return 0;
}
