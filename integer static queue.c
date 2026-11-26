#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int x;

    if(rear == MAX - 1)
        printf("\nQueue Overflow! Cannot insert element.\n");
    else
    {
        printf("\nEnter integer to insert: ");
        scanf("%d", &x);

        if(front == -1)
            front = 0;

        queue[++rear] = x;

        printf("\n%d inserted into the queue successfully.\n", x);
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        printf("\nQueue Underflow! Queue is empty.\n");
    else
    {
        printf("\nDeleted element = %d\n", queue[front]);
        front++;

        if(front > rear)
            front = rear = -1;

        printf("Element deleted successfully.\n");
    }
}

void display()
{
    int i;

    if(front == -1)
        printf("\nQueue is empty. No elements to display.\n");
    else
    {
        printf("\nQueue elements are:\n");

        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);

       //printf("\n");
        //printf("Front element = %d\n", queue[front]);
        //printf("Rear element = %d\n", queue[rear]);
    }
}

int main()
{
    int ch;

    printf("\n===== INTEGER STATIC QUEUE =====\n");

    do
    {
        printf("\n-----------------------------");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n-----------------------------");

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