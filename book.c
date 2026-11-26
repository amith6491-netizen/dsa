#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    float price;
};

int main()
{
    struct Book b[10];
    int i;

    /* Accept details */
    for(i = 0; i < 3; i++)
    {
        printf("\nEnter details of Book %d\n", i + 1);

        printf("Enter Book ID: ");
        scanf("%d", &b[i].id);

        printf("Enter Book Title: ");
        scanf(" %[^\n]", b[i].title);

        printf("Enter Author Name: ");
        scanf(" %[^\n]", b[i].author);

        printf("Enter Price: ");
        scanf("%f", &b[i].price);
    }

    /* Display details */
    printf("\n========== BOOK DETAILS ==========\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("Book ID     : %d\n", b[i].id);
        printf("Book Title  : %s\n", b[i].title);
        printf("Author      : %s\n", b[i].author);
        printf("Price       : %.2f\n", b[i].price);
    }

    return 0;
}