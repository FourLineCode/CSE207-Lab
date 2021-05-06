#include <stdio.h>

// Maximum capacity for heap
#define CAPACITY 100

// Heap related data
int heap[CAPACITY], size = 0;

// Function pointers
void insert(int);
void swap(int*, int*);
void deleteRoot(int);
void printheap();
void heapUp(int);
void findMinimum();

// ==== MAIN ====
int main()
{
	int running = 1;

	while(running)
	{
		printf("======== MAX HEAP ========\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Find Minimum\n");
		printf("4. Print Heap\n");
		printf("5. Exit\n");

		int res;
		printf("Choose > ");
		scanf("%d", &res);

		switch(res)
		{
			case 1:
			{
				int n;
				printf("Enter element: ");
				scanf("%d", &n);
				insert(n);
				break;
			}
			case 2:
			{
				int n;
				printf("Enter element: ");
				scanf("%d", &n);
				deleteRoot(n);
				break;
			}
			case 3:
			{
				findMinimum();
				break;
			}
			case 4:
			{
				printheap();
				break;
			}
			case 5:
			{
				printf("Exited successfully\n");
				running = 0;
				break;
			}
			default:
			{
				printf("Invalid response\n");
				running = 0;
				break;
			}
		}
	}
}

// Print heap elements
void printheap()
{
	printf("Heap elements: ");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", heap[i]);
	}
	printf("\n");
}

// Swap two integers
void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

// Heap up all the values if max heap structure is violated
void heapUp(int i)
{
	if (size == 1)
		return;

	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < size && heap[l] > heap[largest])
		largest = l;

	if (r < size && heap[r] > heap[largest])
		largest = r;

	if (largest != i)
	{
		swap(&heap[i], &heap[largest]);
		heapUp(largest);
	}
}

// Insert an element in the heap
void insert(int n)
{
	if (size == 0)
	{
		heap[0] = n;
		size++;
		return;
	}

	heap[size] = n;
	size++;

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapUp(i);
	}
}

// Delete the root element by swapping the given element
void deleteRoot(int num)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (num == heap[i])
		break;
	}

	if(i == size)
	{
		printf("Element doesn't exist\n");
		return;
	}

	swap(&heap[i], &heap[size - 1]);
	size--;

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapUp(i);
	}
}

// Find the minimum element in the heap
void findMinimum()
{
	if(size <= 0)
	{
		printf("Heap is empty\n");
		return;
	}

	int minimum = heap[0];

	for(int i=1; i<size; i++)
	{
		minimum = heap[i] < minimum ? heap[i] : minimum;
	}

	printf("Minimum element: %d\n", minimum);
}