#include <stdio.h>
#include <stdlib.h>

typedef char StackType;

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

    StackType str[100];
    printf("Enter string > ");
    scanf("%s", &str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            push('(');
        }
        else if (str[i] == ')')
        {
            if (isEmpty())
            {
                printf("\nUnmatched parenthesis for closing bracket!\n");
                return 0;
            }
            pop();
            printf("\nMatched parenthesis!\n");
        }
    }

    if (!isEmpty())
    {
        printf("\nUnmatched parenthesis for opening bracket!\n");
        return 0;
    }

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
        return '\0';
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
        return '\0';
    }

    return stack[topIndex];
}