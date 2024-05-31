#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void Push(struct stack *s, char val)
{
    s->top++;
    s->arr[s->top] = val;
}

void Pop(struct stack *s)
{
    char val = s->arr[s->top];
    s->top--;
}

int parenthesisMatcher(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            Pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{

    char *exp = ")*(3)(";
    if (parenthesisMatcher(exp))
    {
        printf("Parenthesis are matching.\n");
    }
    else
    {
        printf("Parenthesis are not matching.\n");
    }
    return 0;
}
