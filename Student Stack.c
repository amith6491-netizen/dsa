#include <stdio.h>
#define MAX 50

struct student
{
    int roll;
    char name[50];
    float marks;
};

struct student stack[MAX];
int top = -1;

void push()
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;

    printf("Enter Roll Number: ");
    scanf("%d", &stack[top].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", stack[top].name);

    printf("Enter Marks: ");
    scanf("%f", &stack[top].marks);

    printf("Student pushed successfully\n");
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("Deleted student: %s\n", stack[top].name);
        top--;
    }
}

void display()
{
    int i;

    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("\nStudent Stack:\n");

        for(i = top; i >= 0; i--)
        {
            printf("\nRoll No: %d", stack[i].roll);
            printf("\nName: %s", stack[i].name);
            printf("\nMarks: %.2f\n", stack[i].marks);
        }
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Push Student");
        printf("\n2.Pop Student");
        printf("\n3.Display Students");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
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