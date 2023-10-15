#include <stdio.h>

int main(int argc, char const *argv[])
{
    int xm, ym, xn, yn, totalValue = 0;

    scanf("%d %d %d %d", &xm, &ym, &xn, &yn);

    totalValue = (xm - xn < 0 ? -(xm - xn) : xm - xn) + (ym - yn < 0 ? -(ym - yn) : ym - yn);

    printf("%d\n", totalValue);

    return 0;
}
