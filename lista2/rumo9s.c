#include <stdio.h>
#include <string.h>

int somaDosDigitos(char *num)
{
    int i, soma = 0;
    for (i = 0; i < strlen(num); i++)
    {
        soma += num[i] - '0'; // Convertendo o caractere do dígito para o inteiro correspondente
    }
    return soma;
}

int grau9(char *num)
{
    int grau = 0, soma = somaDosDigitos(num);

    // Se a soma dos dígitos não é múltipla de 9, o número não é múltiplo de 9
    if (soma % 9 != 0)
        return 0;

    while (soma % 9 == 0 && soma != 9)
    {
        grau++;
        char strSoma[5]; // Maior soma possível é 9000 para 1000 dígitos todos sendo 9
        sprintf(strSoma, "%d", soma);
        soma = somaDosDigitos(strSoma);
    }
    return grau + 1; // Adiciona 1 ao grau porque o número original já é múltiplo de 9
}

int main()
{
    char num[1001];

    while (1)
    {
        scanf("%s", num);
        if (num[0] == '0')
            break;

        int grau = grau9(num);
        if (grau)
        {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", num, grau);
        }
        else
        {
            printf("%s is not a multiple of 9.\n", num);
        }
    }

    return 0;
}
