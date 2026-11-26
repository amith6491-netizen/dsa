#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left, *right;
};
typedef struct node *nodeptr;
nodeptr list = NULL;
nodeptr getnode(void);
void insert_left(int x);
void insert_last(int x);
void delete_left(void);
void delete_last(void);
void insert_before(int key, int x);
void insert_after(int key, int x);
void delete_before(int key);
void delete_after(int key);
void display(void);
nodeptr getnode(void)
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return temp;
}
void insert_left(int x)
{
    nodeptr temp = getnode();
    temp->info = x;
    temp->left = NULL;
    temp->right = list;
    if (list != NULL)
        list->left = temp;
    list = temp;
    printf("%d inserted at the beginning\n", x);
}
void insert_last(int x)
{
    nodeptr temp = getnode();
    nodeptr p;
    temp->info = x;
    temp->right = NULL;
    if (list == NULL)
    {
        temp->left = NULL;
        list = temp;
    }
    else
    {
        p = list;
        while (p->right != NULL)
            p = p->right;
        p->right = temp;
        temp->left = p;
    }
    printf("%d inserted at the end\n", x);
}
void delete_left(void)
{
    nodeptr temp;
    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = list;
    printf("%d deleted from the beginning\n", temp->info);
    list = list->right;
    if (list != NULL)
        list->left = NULL;
    free(temp);
}
void delete_last(void)
{
    nodeptr temp;
    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = list;
    while (temp->right != NULL)
        temp = temp->right;
    printf("%d deleted from the end\n", temp->info);
    if (temp->left == NULL)
        list = NULL;
    else
        temp->left->right = NULL;
    free(temp);
}
void insert_before(int key, int x)
{
    nodeptr temp, p = list;
    while (p != NULL && p->info != key)
        p = p->right;
    if (p == NULL)
    {
        printf("%d not found in the list\n", key);
        return;
    }
    temp = getnode();
    temp->info = x;
    temp->left = p->left;
    temp->right = p;
    if (p->left != NULL)
        p->left->right = temp;
    else
        list = temp;
    p->left = temp;
    printf("%d inserted before %d\n", x, key);
}
void insert_after(int key, int x)
{
    nodeptr temp, p = list;
    while (p != NULL && p->info != key)
        p = p->right;
    if (p == NULL)
    {
        printf("%d not found in the list\n", key);
        return;
    }
    temp = getnode();
    temp->info = x;
    temp->right = p->right;
    temp->left = p;
    if (p->right != NULL)
        p->right->left = temp;
    p->right = temp;
    printf("%d inserted after %d\n", x, key);
}
void delete_before(int key)
{
    nodeptr p = list;
    nodeptr temp;
    while (p != NULL && p->info != key)
        p = p->right;
    if (p == NULL)
    {
        printf("%d not found in the list\n", key);
        return;
    }
    if (p->left == NULL)
    {
        printf("No node exists before %d\n", key);
        return;
    }
    temp = p->left;
    if (temp->left != NULL)
    {
        temp->left->right = p;
        p->left = temp->left;
    }
    else
    {
        list = p;
        p->left = NULL;
    }
    printf("%d deleted before %d\n", temp->info, key);
    free(temp);
}
void delete_after(int key)
{
    nodeptr p = list;
    nodeptr temp;
    while (p != NULL && p->info != key)
        p = p->right;
    if (p == NULL)
    {
        printf("%d not found in the list\n", key);
        return;
    }
    if (p->right == NULL)
    {
        printf("No node exists after %d\n", key);
        return;
    }
    temp = p->right;
    p->right = temp->right;
    if (temp->right != NULL)
        temp->right->left = p;
    printf("%d deleted after %d\n", temp->info, key);
    free(temp);
}
void display(void)
{
    nodeptr p = list;
    if (p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->right;
    }
    printf("\n");
}
int main(void)
{
    int c, x, key;
    while (1)
    {
        printf("\nMENU\n");
        printf("1. Insert_left\n");
        printf("2. Delete_left\n");
        printf("3. Insert_last\n");
        printf("4. Delete_last\n");
        printf("5. Insert_before\n");
        printf("6. Insert_after\n");
        printf("7. Delete_before\n");
        printf("8. Delete_after\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &c) != 1)
            break;
        switch (c)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert_left(x);
                break;
            case 2:
                delete_left();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &x);
                insert_last(x);
                break;
            case 4:
                delete_last();
                break;
            case 5:
                printf("Enter the existing value: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &x);
                insert_before(key, x);
                break;
            case 6:
                printf("Enter the existing value: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &x);
                insert_after(key, x);
                break;
            case 7:
                printf("Enter the existing value: ");
                scanf("%d", &key);
                delete_before(key);
                break;
            case 8:
                printf("Enter the existing value: ");
                scanf("%d", &key);
                delete_after(key);
                break;
            case 9:
                display();
                break;
            case 10:
                printf("Program terminated\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}