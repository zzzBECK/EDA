#include <stdio.h>

int somaDigitos(char *num)
{
    int sum = 0;

    if (*num == '\0')
        return sum;

    sum += *num - '0';

    return sum + somaDigitos(num + 1);
}

int main(int argc, char const *argv[])
{
    char num[1001];

    scanf("%s", num);

    printf("%d\n", somaDigitos(num));

    return 0;
}
