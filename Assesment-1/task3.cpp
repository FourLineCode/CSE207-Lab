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

    vector<int> values(size);
    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        values[i] = n;

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

    sort(values.begin(), values.end());
    int median = values[ceil(size / 2)];

    Node *curr = head, *prevCurr = NULL;
    while (curr != NULL)
    {
        if (curr->val != median)
        {
            prevCurr = curr;
            curr = curr->next;
            continue;
        }
        Node *middle = head, *prevMiddle = NULL;
        for (int i = 0; i < floor(size / 2); i++)
        {
            prevMiddle = middle;
            middle = middle->next;
        }

        if (prevCurr != NULL)
            prevCurr->next = middle;
        else
            head = middle;

        if (prevMiddle != NULL)
            prevMiddle->next = curr;
        else
            head = curr;

        Node *temp = middle->next;
        middle->next = curr->next;
        curr->next = temp;

        break;
    }

    Node *trav = head;
    while (trav != NULL)
    {
        cout << trav->val << " ";
        trav = trav->next;
    }
    cout << endl;
}