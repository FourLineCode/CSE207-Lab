#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int val;
    Node *prev;
    Node *next;
} Node;

int main()
{
    Node *head = NULL, *tail = NULL;
    int size;
    cin >> size;

    while (size--)
    {
        int n;
        cin >> n;

        Node *temp = (Node *)malloc(sizeof(Node));
        temp->val = n;
        temp->next = NULL;

        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
            tail = temp;
            continue;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    int N;
    cin >> N;

    while (N--)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        tail->next = NULL;
    }

    Node *trav = head;
    while (trav != NULL)
    {
        cout << trav->val << " ";
        trav = trav->next;
    }
    cout << endl;
}