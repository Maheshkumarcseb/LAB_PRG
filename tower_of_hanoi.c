#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary peg using destination as temporary peg
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination peg
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary peg to destination peg using source as temporary peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    printf("Tower of Hanoi solution for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, and C represent the three pegs
    
    return 0;
}

