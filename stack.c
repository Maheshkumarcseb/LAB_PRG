#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> // Include string.h for string operations 
#define MAX 10 
int stack_arr[MAX]; 
int top = -1; 
void push(int item); 
int pop(); 
int peek(); 
int isEmpty(); 
int isFull(); 
void display(); 
int isPalindrome(char str[]); // Function to check if a string is a palindrome 
int main() { 
int choice, item; 
char str[MAX]; 
while (1) { 
printf("\n1.Push\n"); 
printf("2.Pop\n"); 
printf("3.Display the top element\n"); 
printf("4.Display all stack elements\n"); 
printf("5.Check Palindrome\n"); // Option to check a string for palindrome 
printf("6.Quit\n"); 
printf("\nEnter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("\nEnter the item to be pushed: "); 
scanf("%d", &item); 
push(item); 
break; 
case 2: 
item = pop(); 
printf("\nPopped item is: %d\n", item); 
break; 
case 3: 
printf("\nItem at the top is: %d\n", peek()); 
break; 
case 4: 
display(); 
break; 
case 5: 
printf("\nEnter a string to check if it's a palindrome: "); 
scanf("%s", str); 
if (isPalindrome(str)) { 
printf("%s is a palindrome.\n", str); 
} else { 
printf("%s is not a palindrome.\n", str); 
}break; 
case 6: 
exit(0); 
default: 
printf("\nWrong choice\n"); 
} /*End of switch*/ 
}     /*End of while*/ 
return 0; 
} /*End of main()*/ 
void push(int item) { 
if (isFull()) { 
printf("\nStack Overflow\n"); 
return; 
} 
top = top + 1; 
stack_arr[top] = item; 
} /*End of push()*/ 
int pop() { 
int item; 
if (isEmpty()) { 
printf("\nStack Underflow\n"); 
exit(1); 
} 
item = stack_arr[top]; 
top = top - 1; 
return item; 
} /*End of pop()*/ 
int peek() { 
if (isEmpty()) { 
printf("\nStack Underflow\n"); 
exit(1); 
} 
return stack_arr[top]; 
} /*End of peek()*/ 
int isEmpty() { 
if (top == -1) 
return 1; 
else 
return 0; 
} /*End of isEmpty*/ 
int isFull() { 
if (top == MAX - 1) 
return 1; 
else 
return 0; 
} /*End of isFull()*/ 
void display() { 
int i; 
if (isEmpty()) { 
printf("\nStack is empty\n"); 
return; 
} 
printf("\nStack elements:\n\n"); 
for (i = top; i >= 0; i--) 
printf(" %d\n", stack_arr[i]); 
printf("\n"); 
} /*End of display()*/ 
int isPalindrome(char str[]) { 
int i, len; 
len = strlen(str); 
for (i = 0; i < len; i++) { 
push(str[i]); // Push characters of the string onto the stack 
} 
for (i = 0; i < len; i++) { 
char ch = pop(); 
if (ch != str[i]) { 
return 0; // Not a palindrome 
} 
} 
return 1; // Palindrome
}
