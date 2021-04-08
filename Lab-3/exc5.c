#include <stdio.h>
#include <stdlib.h>

typedef int StackType;

// Global variables
int topIndex = -1, size = 10;
StackType *stack;

// Function pointers
void push(StackType);
StackType pop();
StackType top();
int isEmpty();

// ===== MAIN =====
int main()
{
    stack = (StackType *)calloc(size, sizeof(StackType));

    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        push(n % 2);
        n /= 2;
    }

    int ans = 0;
    while (!isEmpty())
    {
        ans = (ans * 10) + pop();
    }

    printf("Result = %d\n", ans);

    return 0;
}

// Push an element to the stack
void push(StackType el)
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

    return stack[topIndex--];
}

// Check weather stack is empty
int isEmpty()
{
    return topIndex < 0;
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