#include <stdio.h>

struct Salary
{
    float basic;
    float hra;
    float da;
    float gross;
};

struct Employee
{
    int id;
    char name[30];
    struct Salary salary;   // Nested structure
};

int main()
{
    struct Employee e;

    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Employee Name: ");
    scanf("%s", e.name);

    printf("Enter Basic Salary: ");
    scanf("%f", &e.salary.basic);

    e.salary.hra = e.salary.basic * 0.20;
    e.salary.da = e.salary.basic * 0.10;
    e.salary.gross = e.salary.basic + e.salary.hra + e.salary.da;

    printf("\n------ EMPLOYEE SALARY REPORT ------\n");
    printf("Employee ID   : %d\n", e.id);
    printf("Employee Name : %s\n", e.name);
    printf("Basic Salary  : %.2f\n", e.salary.basic);
    printf("HRA           : %.2f\n", e.salary.hra);
    printf("DA            : %.2f\n", e.salary.da);
    printf("Gross Salary  : %.2f\n", e.salary.gross);
    printf("------------------------------------\n");

    return 0;
}