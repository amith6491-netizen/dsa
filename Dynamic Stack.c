#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;
    int x;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter integer: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("Element pushed\n");
}

void pop()
{
    struct node *temp;

    if(top == NULL)
        printf("Stack Underflow\n");
    else
    {
        temp = top;
        printf("Deleted element = %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp = top;

    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements:\n");
        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 4);

    return 0;
}