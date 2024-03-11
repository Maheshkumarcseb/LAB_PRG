#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to represent employee data
struct Employee
{
    char ssn[20];
    char name[50];
    char dept[50];
    char designation[50];
    float sal;
    long long int phNo;
    struct Employee *prev;
    struct Employee *next;
};
typedef struct Employee Employee;
Employee *head = NULL;
Employee *tail = NULL;
// Function to create a new employee node
Employee *createEmployee()
{
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
    if (newEmployee == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter SSN: ");
    scanf("%s", newEmployee->ssn);
    printf("Enter Name: ");
    scanf("%s", newEmployee->name);
    printf("Enter Department: ");
    scanf("%s", newEmployee->dept);
    printf("Enter Designation: ");
    scanf("%s", newEmployee->designation);
    printf("Enter Salary: ");
    scanf("%f", &newEmployee->sal);
    printf("Enter Phone Number: ");
    scanf("%lld", &newEmployee->phNo);
    newEmployee->prev = NULL;
    newEmployee->next = NULL;
    return newEmployee;
}
// Function to insert an employee at the end of the list
void insertEnd()
{
    Employee *newEmployee = createEmployee();
    if (head == NULL)
    {
        head = newEmployee;
        tail = newEmployee;
    }
    else
    {
        newEmployee->prev = tail;
        tail->next = newEmployee;
        tail = newEmployee;
    }
    printf("Employee added at the end.\n");
}
// Function to delete an employee from the end of the list
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete.\n");
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
        printf("Employee deleted from the end.\n");
    }
    else
    {
        Employee *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        printf("Employee deleted from the end.\n");
    }
}
// Function to insert an employee at the front of the list
void insertFront()
{
    Employee *newEmployee = createEmployee();
    if (head == NULL)
    {
        head = newEmployee;
        tail = newEmployee;
    }
    else
    {
        newEmployee->next = head;
        head->prev = newEmployee;
        head = newEmployee;
    }
    printf("Employee added at the front.\n");
}
// Function to delete an employee from the front of the list
void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete.\n");
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
        printf("Employee deleted from the front.\n");
    }
    else
    {
        Employee *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("Employee deleted from the front.\n");
    }
}
// Function to display the status of the linked list and count the number of nodes
void displayAndCount()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        Employee *current = head;
        int count = 0;
        printf("Employee Data:\n");
        while (current != NULL)
        {
            printf("SSN: %s, Name: %s, Department: %s, Designation: %s, Salary: %.2f, Phone:% lld\n ", 
            current->ssn,current->name, current->dept, current->designation, current->sal,current->phNo);
            current = current->next;
            count++;
        }
        printf("Total Employees: %d\n", count);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete from End\n");
        printf("3. Insert at Front\n");
        printf("4. Delete from Front\n");
        printf("5. Display and Count\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertEnd();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            insertFront();
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            displayAndCount();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
