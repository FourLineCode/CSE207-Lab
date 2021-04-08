#include <stdio.h>
#include <stdlib.h>

void sortarray(int size, int *ptr)
{
    int swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (*(ptr + i) > *(ptr + i + 1))
            {
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + i + 1);
                *(ptr + i + 1) = temp;

                swapped = 1;
            }
        }
    }
}

int main()
{
    int size;
    printf("Size of list: ");
    scanf("%d", &size);

    int *listPtr = (int *)malloc(size * sizeof(int));

    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", listPtr + i);
    }

    sortarray(size, listPtr);

    printf("\nElements after sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(listPtr + i));
    }
    puts("");

    return 0;
}
