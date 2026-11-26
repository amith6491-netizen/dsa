#include <stdio.h>

struct Student
{
    char name[30];
    int rollno;
    int m1, m2, m3;
    int total;
    float percentage;
};

int main()
{
    struct Student s;

    printf("Enter student name: ");
    scanf("%s", s.name);

    printf("Enter roll number: ");
    scanf("%d", &s.rollno);

    printf("Enter marks of 3 subjects:\n");
    scanf("%d %d %d", &s.m1, &s.m2, &s.m3);

    s.total = s.m1 + s.m2 + s.m3;
    s.percentage = s.total / 3.0;

    printf("\n----- STUDENT MARKS CARD -----\n");
    printf("Name       : %s\n", s.name);
    printf("Roll No    : %d\n", s.rollno);
    printf("Subject 1  : %d\n", s.m1);
    printf("Subject 2  : %d\n", s.m2);
    printf("Subject 3  : %d\n", s.m3);
    printf("Total      : %d\n", s.total);
    printf("Percentage : %.2f%%\n", s.percentage);

    return 0;
}