#include <stdio.h>

int main(int argc, char const *argv[])
{

    int a, b, c, equal = 0;

    scanf("%d %d %d", &a, &b, &c);

    equal = a == b && b == c;

    if (equal)
        printf("empate\n");
    else
        printf("%c\n", a != b && a != c ? 'A' : b != a && b != c ? 'B'
                                                                 : 'C');

    return 0;
}
