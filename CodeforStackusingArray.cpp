#include <stdio.h>
#include <stdlib.h>

#define MAXSTK 100

int top = -1;
int items[MAXSTK];

// Function prototypes
int Isempty();
int Isfull();
void Push(int);
int Pop();
void Display();

int main() {
    int x;
    int choice;

    while (1) {
        printf("\n 1-PUSH");
        printf("\n 2-POP");
        printf("\n 3-DISPLAY");
        printf("\n 4-QUIT");
        printf("\n Enter your choice: ");
        
        // Reading the choice using scanf to avoid issues with leftover newline characters
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n Enter the element to be pushed: ");
                scanf("%d", &x);
                Push(x);
                break;
            case 2:
                x = Pop();
                if (x != -1) { // Only print if pop is successful
                    printf("\n Popped element is %d\n", x);
                }
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(0); // Exit the program
            default:
                printf("\n Wrong choice! Try again.\n");
        }
    }
    return 0;
}

// Check if the stack is empty
int Isempty() {
    return top == -1;
}

// Check if the stack is full
int Isfull() {
    return top == MAXSTK - 1;
}

// Push an element onto the stack
void Push(int x) {
    if (Isfull()) {
        printf("\n Stack full\n");
        return;
    }
    items[++top] = x;
}

// Pop an element from the stack
int Pop() {
    if (Isempty()) {
        printf("\n Stack empty\n");
        return -1;  // Return a special value to indicate the stack is empty
    }
    return items[top--];
}

// Display all elements in the stack
void Display() {
    if (Isempty()) {
        printf("\n Stack empty\n");
        return;
    }
    printf("\n Elements in the Stack are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", items[i]);
    }
}
