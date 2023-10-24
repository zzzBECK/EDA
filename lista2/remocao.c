#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p == NULL || p->prox == NULL)
    {
        return -1; // Não é possível remover
    }

    celula *tmp = p->prox;
    p->prox = tmp->prox;
    free(tmp);
    return 0; // Remoção bem-sucedida
}

void remove_elemento(celula *le, int x)
{
    for (celula *p = le; p->prox != NULL; p = p->prox)
    {
        if (p->prox->dado == x)
        {
            remove_depois(p);
            break; // Sai após remover a primeira ocorrência
        }
    }
}

void remove_todos_elementos(celula *le, int x)
{
    for (celula *p = le; p->prox != NULL;)
    {
        if (p->prox->dado == x)
        {
            remove_depois(p);
            // Não avançamos o ponteiro, pois precisamos verificar o próximo após a remoção
        }
        else
        {
            p = p->prox; // Avança para o próximo nó
        }
    }
}

// Funções de teste para verificar a funcionalidade

void print_list(celula *le)
{
    for (celula *p = le->prox; p != NULL; p = p->prox)
    {
        printf("%d -> ", p->dado);
    }
    printf("NULL\n");
}

int main()
{
    // Exemplo de uso
    celula le = {0, NULL};
    celula a = {1, NULL}, b = {2, NULL}, c = {2, NULL}, d = {3, NULL}, e = {2, NULL};
    le.prox = &a;
    a.prox = &b;
    b.prox = &c;
    c.prox = &d;
    d.prox = &e;

    printf("Lista original: ");
    print_list(&le);

    remove_elemento(&le, 2);
    printf("Lista após remover primeira ocorrência de 2: ");
    print_list(&le);

    remove_todos_elementos(&le, 2);
    printf("Lista após remover todas ocorrências de 2: ");
    print_list(&le);

    return 0;
}
