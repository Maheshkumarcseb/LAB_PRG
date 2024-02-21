#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Structure to represent student data 
struct Student { 
char usn[20]; 
char name[50]; 
char program[50]; 
int sem; 
long long int phNo; 
struct Student *next; 
}; 
typedef struct Student Student; 
Student *head = NULL; 
// Function to create a new student node 
Student *createStudent() { 
Student *newStudent = (Student *)malloc(sizeof(Student)); 
if (newStudent == NULL) { 
printf("Memory allocation failed.\n"); 
exit(1); 
} 
printf("Enter USN: "); 
scanf("%s", newStudent->usn); 
printf("Enter Name: "); 
scanf("%s", newStudent->name); 
printf("Enter Program: "); 
scanf("%s", newStudent->program); 
printf("Enter Semester: "); 
scanf("%d", &newStudent->sem); 
printf("Enter Phone Number: "); 
scanf("%lld", &newStudent->phNo); 
newStudent->next = NULL; 
return newStudent; 
} 
// Function to insert a student at the front of the list 
void insertFront() { 
Student *newStudent = createStudent(); 
newStudent->next = head; 
head = newStudent; 
printf("Student added at the front.\n"); 
} 
// Function to insert a student at the end of the list 
void insertEnd() { 
Student *newStudent = createStudent(); 
if (head == NULL) { 
head = newStudent; 
} else { 
Student *current = head; 
while (current->next != NULL) { 
current = current->next; 
} 
current->next = newStudent; 
} 
printf("Student added at the end.\n"); 
} 
// Function to delete a student from the front of the list (stack-like operation) 
void deleteFront() { 
if (head == NULL) { 
printf("List is empty, cannot delete.\n"); 
} else { 
Student *temp = head; 
head = head->next; 
free(temp); 
printf("Student deleted from the front.\n"); 
} 
} 
// Function to display the status of the linked list and count the number of nodes 
void displayAndCount() { 
if (head == NULL) { 
printf("List is empty.\n"); 
} else { 
Student *current = head; 
int count = 0; 
printf("Student Data:\n"); 
while (current != NULL) { 
printf("USN: %s, Name: %s, Program: %s, Semester: %d, Phone: %lld\n", 
current->usn, current->name, current->program, current->sem, current->phNo); 
current = current->next; 
            count++; 
        } 
        printf("Total Students: %d\n", count); 
    } 
} 
 
int main() { 
    int choice; 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Insert at Front\n"); 
        printf("2. Insert at End\n"); 
        printf("3. Delete from Front\n"); 
        printf("4. Display and Count\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                insertFront(); 
                break; 
            case 2: 
                insertEnd(); 
                break; 
            case 3: 
                deleteFront(); 
                break; 
            case 4: 
                displayAndCount(); 
                break; 
            case 5: 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
 
    return 0; 
}