#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

void deleteStack(Stack *stack)
{
    if (stack)
    {
        if (stack->array)
            free(stack->array);
        free(stack);
    }
}

int canReorder(int *trucks, int n)
{
    Stack *stack = createStack(n);
    int need = 1;
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(stack) && peek(stack) == need)
        {
            pop(stack);
            need++;
        }

        if (trucks[i] == need)
        {
            need++;
        }
        else
        {
            push(stack, trucks[i]);
        }
    }

    while (!isEmpty(stack))
    {
        if (pop(stack) != need)
        {
            deleteStack(stack);
            return 0;
        }
        need++;
    }

    deleteStack(stack);
    return 1;
}

int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        int *trucks = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &trucks[i]);
        }

        if (canReorder(trucks, n))
            printf("yes\n");
        else
            printf("no\n");

        free(trucks);
    }

    return 0;
}
