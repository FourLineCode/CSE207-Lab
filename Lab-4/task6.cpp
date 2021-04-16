#include <iostream>
#include <stack>
using namespace std;

typedef int QueueType;
size_t SIZE = 10;

QueueType *queue = NULL;
int first = -1, last = -1;

void print();
void enqueue(QueueType);
QueueType dequeue();
QueueType front();
QueueType back();
bool isFull();
bool isEmpty();

int main()
{

    stack<int> s;
    int size;
    cin >> size;
    SIZE = size;

    queue = (QueueType *)malloc(SIZE * sizeof(QueueType));

    printf("Enter stack elements: ");
    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;

        s.push(n);
    }

    while (s.size())
    {
        enqueue(s.top());
        s.pop();
    }

    printf("Queue elements: ");
    print();
}

void print()
{
    if (isEmpty())
    {
        printf("Print Error: Queue is empty!\n");
        return;
    }

    int i;
    for (i = first; i != last; i = (i + 1) % SIZE)
        cout << queue[i] << " ";
    cout << queue[i] << endl;
}

void enqueue(QueueType n)
{
    if (isFull())
    {
        printf("Queue is full!\n");
        return;
    }

    if (first == -1)
        first = 0;
    last = (last + 1) % SIZE;
    queue[last] = n;
}

QueueType dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return -1e9;
    }

    int element = queue[first];
    if (first == last)
    {
        first = -1;
        last = -1;
    }
    else
    {
        first = (first + 1) % SIZE;
    }

    return element;
}

QueueType front()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return -1e9;
    }

    return queue[first];
}

QueueType back()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return -1e9;
    }

    return queue[last];
}

bool isFull()
{
    if (first == 0 && last == SIZE - 1)
    {
        return true;
    }
    if (first == last + 1)
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (first == -1)
        return true;
    else
        return false;
}