#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a, g, ra, rg;

    scanf("%f %f %f %f", &a, &g, &ra, &rg);

    if (ra / a > rg / g)
        printf("A\n");
    else
        printf("G\n");

    return 0;
}
