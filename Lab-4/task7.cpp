#include <iostream>
using namespace std;

typedef int QueueType;
size_t SIZE = 10;

QueueType *queue1 = NULL, *queue2 = NULL;
int first1 = -1, last1 = -1;
int first2 = -1, last2 = -1;

void print(QueueType *, int, int);
void enqueue(QueueType, QueueType *, int *, int *);
QueueType dequeue(QueueType *, int *, int *);
QueueType front(QueueType *, int, int);
QueueType back(QueueType *, int, int);
bool isFull(int, int);
bool isEmpty(int);

int main()
{
    printf("Enter number of elements: ");
    int size;
    cin >> size;
    SIZE = size;

    queue1 = (QueueType *)malloc(SIZE * sizeof(QueueType));
    queue2 = (QueueType *)malloc(SIZE * sizeof(QueueType));

    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;

        enqueue(n, queue1, &first1, &last1);
    }

    for (int i = 0; i < size; i++)
    {
        int el = dequeue(queue1, &first1, &last1);
        if (el < 0)
            continue;
        enqueue(el, queue2, &first2, &last2);
    }

    printf("Queue: ");
    print(queue2, first2, last2);
}

void print(QueueType *q, int f, int l)
{
    if (isEmpty(f))
    {
        printf("Print Error: Queue is empty!\n");
        return;
    }

    int i;
    for (i = f; i != l; i = (i + 1) % SIZE)
        cout << q[i] << " ";
    cout << q[i] << endl;
}

void enqueue(QueueType n, QueueType *q, int *f, int *l)
{
    if (isFull(*f, *l))
    {
        printf("Queue is full!\n");
        return;
    }

    if (*f == -1)
        *f = 0;
    *l = (*l + 1) % SIZE;
    q[*l] = n;
}

QueueType dequeue(QueueType *q, int *f, int *l)
{
    if (isEmpty(*f))
    {
        printf("Queue is empty!\n");
        return -1e9;
    }

    int element = q[*f];
    if (*f == *l)
    {
        *f = -1;
        *l = -1;
    }
    else
    {
        *f = (*f + 1) % SIZE;
    }

    return element;
}

QueueType front(QueueType *q, int f, int l)
{
    if (isEmpty(f))
    {
        printf("Queue is empty!\n");
        return -1e9;
    }

    return q[f];
}

QueueType back(QueueType *q, int f, int l)
{
    if (isEmpty(f))
    {
        printf("Queue is empty!\n");
        return -1e9;
    }

    return q[l];
}

bool isFull(int f, int l)
{
    if (f == 0 && l == SIZE - 1)
    {
        return true;
    }
    if (f == l + 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(int f)
{
    if (f == -1)
        return true;
    else
        return false;
}