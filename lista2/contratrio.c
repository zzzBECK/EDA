#include <stdio.h>

void invert(char *str)
{
    if (*str == '\0')
        return;

    invert(str + 1);
    printf("%c", *str);
}

int main(int argc, char const *argv[])
{

    char str[1001];

    scanf("%[^\n]", str);

    invert(str);
    printf("\n");

    return 0;
}
