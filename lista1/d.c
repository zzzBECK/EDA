#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, x, y, z;

    scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);

    printf("%d\n", (x / a) * (y / b) * (z / c));

    return 0;
}
