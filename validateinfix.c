#include <stdio.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char exp[100];
    int i, valid = 1;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
            push(exp[i]);

        else if(exp[i] == ')')
        {
            if(top == -1)
            {
                valid = 0;
                break;
            }
            else
                pop();
        }
    }

    if(top != -1)
        valid = 0;

    if(valid == 1)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}