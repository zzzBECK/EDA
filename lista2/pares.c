#include <stdio.h>
#include <string.h>

int contarPares(char *str)
{
    if (strlen(str) < 3)
        return 0;

    if (str[0] == str[2])
    {
        return 1 + contarPares(str + 1);
    }
    else
    {
        return contarPares(str + 1);
    }
}

int main()
{
    char str[201];
    scanf("%s", str);
    printf("%d\n", contarPares(str));
    return 0;
}
