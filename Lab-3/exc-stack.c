#include <stdio.h>
#include <stdlib.h>

typedef int StackType;

// Global variables
int topIndex = -1, size = 10;
StackType *stack;

// Function pointers
void prompt(char s[]);
void display();
void push();
StackType pop();
StackType top();
int isEmpty();

// ===== MAIN =====
int main()
{
    stack = (StackType *)calloc(size, sizeof(StackType));

    int running = 1;

    while (running)
    {
        printf("\tMENU\n");
        printf("1. Print stack\n");
        printf("2. Push stack\n");
        printf("3. Pop stack\n");
        printf("4. Exit\n");
        printf("\n");

        prompt("Enter your choice");

        int response;
        scanf("%d", &response);
        printf("\n");

        switch (response)
        {
        case 1:
        {
            display();
            break;
        }
        case 2:
        {
            push();
            display();
            break;
        }
        case 3:
        {
            pop();
            display();
            break;
        }
        case 4:
        {
            running = 0;
            printf("\nProgram exited successfully!\n");
            break;
        }
        default:
        {
            running = 0;
            printf("\nInvalid response!\nProgram exited successfully!\n");
            break;
        }
        }
        printf("\n");
    }

    return 0;
}

// Print a input prompt from string
void prompt(char s[])
{
    printf("\n%s > ", s);
}

// Display the stack in console
void display()
{
    if (topIndex < 0)
    {
        return;
    }

    printf("\nThe stack elements are: ");

    for (int i = topIndex; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n\n");
}

// Push an element to the stack
void push()
{
    if (topIndex + 1 >= size)
    {
        size *= 2;
        StackType *temp = (StackType *)calloc(size, sizeof(StackType));

        for (int i = 0; i <= topIndex; i++)
        {
            temp[i] = stack[i];
        }

        StackType *prev = stack;
        stack = temp;

        free(prev);
    }

    prompt("Enter element to push");

    StackType el;
    scanf("%d", &el);

    stack[++topIndex] = el;
}

// Pop an element from the top of the stack and return it
StackType pop()
{
    if (topIndex < 0)
    {
        printf("The stack is empty!\n");
        return -2e9;
    }

    printf("\nThe popped element: %d\n", stack[topIndex]);

    return stack[topIndex--];
}

// Peek the top value of stack
StackType top()
{
    if (topIndex < 0)
    {
        printf("The stack is empty!\n");
        return -2e9;
    }

    return stack[topIndex];
}

// Check weather stack is empty
int isEmpty()
{
    return topIndex < 0;
}