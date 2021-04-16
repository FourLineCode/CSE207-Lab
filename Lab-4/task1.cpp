#include <iostream>
using namespace std;

typedef int QueueType;
const size_t SIZE = 10;

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
    queue = (QueueType *)malloc(SIZE * sizeof(QueueType));

    bool running = true;

    while (running)
    {
        string s;
        int n;
        cin >> s;

        if (s == "enq")
        {
            cin >> n;
            enqueue(n);
            print();
        }
        else if (s == "deq")
        {
            dequeue();
            print();
        }
        else if (s == "front")
        {
            cout << front() << endl;
        }
        else if (s == "back")
        {
            cout << back() << endl;
        }
        else if (s == "prnt")
        {
            print();
        }
        else if (s == "exit")
        {
            running = false;
        }
        else
        {
            printf("\nInvalid Command!\n");
            running = false;
        }
    }
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