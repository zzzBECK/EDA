#include <stdio.h>

void processString(char *str)
{
    if (*str == '\0')
        return;

    if (*str == 'x')
    {
        processString(str + 1);
        printf("x");
    }
    else
    {
        printf("%c", *str);
        processString(str + 1);
    }
}

int main()
{
    char entrada[1001];

    scanf("%[^\n]", entrada);

    processString(entrada);

    printf("\n");
    return 0;
}
