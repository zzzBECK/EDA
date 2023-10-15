#include <stdio.h>
#include <string.h>

// Encontra a primeira ocorrência de sub em str começando da posição start
int findFirst(char *str, char *sub, int start)
{
    if (strstr(str + start, sub) == NULL)
        return -1;                         // Se não houver ocorrência, retorna -1
    return strstr(str + start, sub) - str; // Retorna a posição da primeira ocorrência
}

// Encontra a próxima ocorrência de sub em str depois da posição start
int findNext(char *str, char *sub, int start)
{
    if (strstr(str + start + 1, sub) == NULL)
        return -1;
    return strstr(str + start + 1, sub) - str;
}

int maxSubstring(char *str, char *sub)
{
    int first = findFirst(str, sub, 0);
    if (first == -1)
        return 0; // Se não há ocorrência de sub, retorna 0

    int next = findNext(str, sub, first);
    if (next == -1)
        return strlen(sub); // Se há apenas uma ocorrência, retorna o tamanho de sub

    // Calcula o tamanho da substring entre first e next
    int currentLength = next + strlen(sub) - first;

    // Chama a função recursivamente para o restante da string depois de "first"
    int remaining = maxSubstring(str + first + 1, sub);

    if (currentLength > remaining)
        return currentLength;
    return remaining;
}

int main()
{
    char str[101], sub[101];
    scanf("%s", str);
    scanf("%s", sub);
    printf("%d\n", maxSubstring(str, sub));
    return 0;
}
