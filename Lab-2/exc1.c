#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Linked List Node Type
typedef struct Node
{
    int val;
    struct Node *next;
} Node;

// Global variables
Node *head = NULL, *tail = NULL;
size_t SIZE = 0;

// Function pointer declaration
void prompt(char s[]);
void display();
void create();
void insert_end();
void insert_beginning();
void insert_at_position();
void delete_end();
void delete_beginning();
void delete_at_position();
void reverse_list();
void remove_duplicate();
void remove_element_from_position(size_t);

// === Main Function ===
int main()
{
    int running = 1;

    while (running)
    {
        printf("\tMENU\n");
        printf("1. Create Linked List\n");
        printf("2. Display List\n");
        printf("3. Insert Node at End\n");
        printf("4. Insert Node at Beginning\n");
        printf("5. Insert Node at Any Position\n");
        printf("6. Delete Node from Last Position\n");
        printf("7. Delete Node from First Position\n");
        printf("8. Delete Node from Any Position\n");
        printf("9. Reverse Linked List\n");
        printf("10. Remove Duplicate Data from List\n");
        printf("11. Exit\n");
        printf("\n");

        prompt("Enter your choice");

        int response;
        scanf("%d", &response);

        switch (response)
        {
        case 1:
        {
            create();
            display();
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            insert_end();
            display();
            break;
        }
        case 4:
        {
            insert_beginning();
            display();
            break;
        }
        case 5:
        {
            insert_at_position();
            display();
            break;
        }
        case 6:
        {
            delete_end();
            display();
            break;
        }
        case 7:
        {
            delete_beginning();
            display();
            break;
        }
        case 8:
        {
            delete_at_position();
            display();
            break;
        }
        case 9:
        {
            reverse_list();
            display();
            break;
        }
        case 10:
        {
            remove_duplicate();
            display();
            break;
        }
        case 11:
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
    }

    return 0;
}

// Print a input prompt from string
void prompt(char s[])
{
    printf("\n%s > ", s);
}

// Display the current list
void display()
{
    if (head == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }
    Node *temp = head;

    printf("\nList elemets are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n\nPress any key to continue...");

    getche();
    printf("\n\n");
}

// Create the list if it has not been initialized
void create()
{
    if (head != NULL)
    {
        printf("\nLinked List already exists!\n");
        return;
    }

    int size;
    prompt("Enter number of elements");
    scanf("%d", &size);
    SIZE += size;

    prompt("Enter list elements");
    for (int i = 0; i < size; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        scanf("%d", &(temp->val));
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            continue;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}

// Insert a node at the end of list
void insert_end()
{
    if (head == NULL)
    {
        printf("\nList has not been created yet!\n");
        return;
    }

    prompt("Enter element to insert at end");
    Node *temp = (Node *)malloc(sizeof(Node));
    scanf("%d", &(temp->val));
    temp->next = NULL;

    tail->next = temp;
    tail = temp;

    SIZE++;
}

// Insert a node at the beginning of list
void insert_beginning()
{
    if (head == NULL)
    {
        printf("\nList has not been created yet!\n");
        return;
    }

    prompt("Enter element to insert at beginning");
    Node *temp = (Node *)malloc(sizeof(Node));
    scanf("%d", &(temp->val));
    temp->next = head;

    head = temp;

    SIZE++;
}

// Insert a node at a specified position (0-SIZE)
void insert_at_position()
{
    if (head == NULL)
    {
        printf("\nList has not been created yet!\n");
        return;
    }

    prompt("Enter position");
    int pos;
    scanf("%d", &pos);

    if (pos > SIZE)
    {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == SIZE)
    {
        insert_end();
        return;
    }

    Node *curr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        curr = curr->next;
    }

    prompt("Enter element to insert at position");
    Node *temp = (Node *)malloc(sizeof(Node));
    scanf("%d", &(temp->val));

    if (pos == 0)
    {
        temp->next = head;
        head = temp;

        SIZE++;
        return;
    }

    temp->next = curr->next;
    curr->next = temp;

    SIZE++;
}

// Delete the last element
void delete_end()
{
    if (head == NULL || SIZE <= 0)
    {
        return;
    }

    Node *curr = head, *prev = NULL;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    tail = prev;

    free(curr);

    SIZE--;
}

// Delete the first element
void delete_beginning()
{
    if (head == NULL || SIZE <= 0)
    {
        return;
    }

    Node *temp = head;
    head = head->next;

    free(temp);

    SIZE--;
}

// Delete the element at specified position
void delete_at_position()
{
    if (head == NULL || SIZE <= 0)
    {
        return;
    }

    prompt("Enter position");
    int pos;
    scanf("%d", &pos);

    if (pos >= SIZE)
    {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == 0)
    {
        delete_beginning();
        return;
    }

    if (pos == SIZE - 1)
    {
        delete_end();
        return;
    }

    Node *temp = head, *curr = NULL;
    while (pos--)
    {
        curr = temp;
        temp = temp->next;
    }

    curr->next = curr->next->next;

    free(temp);

    SIZE--;
}

// Reverse the linked list
void reverse_list()
{
    if (head == NULL || SIZE <= 0)
    {
        return;
    }

    Node *curr = head, *prev = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    tail = head;
    head = prev;
}

// Remove duplicate element from the linked list
void remove_duplicate()
{
    if (head == NULL || SIZE <= 0)
    {
        return;
    }

    Node *curr = head;
    int pos = 0;

    while (curr != NULL)
    {
        Node *ptr = curr->next;
        int ptrPos = pos + 1;
        while (ptr != NULL)
        {
            if (curr->val == ptr->val)
            {
                ptr = ptr->next;
                remove_element_from_position(ptrPos);
                continue;
            }
            ptr = ptr->next;
            ptrPos++;
        }

        curr = curr->next;
        pos++;
    }
}

// Remove element from specified position (remove_duplicate() dependency)
void remove_element_from_position(size_t pos)
{
    if (pos >= SIZE)
    {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == 0)
    {
        delete_beginning();
        return;
    }

    if (pos == SIZE - 1)
    {
        delete_end();
        return;
    }

    Node *temp = head, *curr = NULL;
    while (pos--)
    {
        curr = temp;
        temp = temp->next;
    }

    curr->next = curr->next->next;

    free(temp);

    SIZE--;
}
