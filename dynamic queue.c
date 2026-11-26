#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue()
{
    struct node *newnode;
    int x;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\nEnter integer to insert: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("\n%d inserted into the queue successfully.\n", x);
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
        printf("\nQueue Underflow! Queue is empty.\n");
    else
    {
        temp = front;

        printf("\nDeleted element = %d\n", front->data);

        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);

        printf("Element deleted successfully.\n");
    }
}

void display()
{
    struct node *temp = front;

    if(front == NULL)
        printf("\nQueue is empty. No elements to display.\n");
    else
    {
        printf("\nQueue elements are:\n");

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        //printf("\n");
        //printf("Front element = %d\n", front->data);
        //printf("Rear element = %d\n", rear->data);
    }
}

int main()
{
    int ch;

    printf("\n===== DYNAMIC QUEUE USING LINKED LIST =====\n");

    do
    {
        printf("\n--------------------------------");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n--------------------------------");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting the program...\n");
                printf("Thank you!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(ch != 4);

    return 0;
}