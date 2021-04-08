#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Linked List Node Type
typedef struct Node
{
    int val;
    struct Node *next;
} Node;

// Function pointer declaration
Node *reverse_list(Node *);

// === Main Function ===
int main()
{
    Node *head = NULL, *tail = NULL;

    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter %d numbers: ", size);
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
        tail->next = temp;
        tail = temp;
    }

    Node *temp = head;
    printf("\nList before reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    temp = reverse_list(head);

    printf("\nList after reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}

// Reverse linked list
Node *reverse_list(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rem = reverse_list(head->next);
    head->next->next = head;

    head->next = NULL;

    return rem;
}