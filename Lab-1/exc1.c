#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Size of list: ");
    scanf("%d", &size);

    int *listPtr = (int *)malloc(size * sizeof(int));
    int max = -2e9;

    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", listPtr + i);
        max = *(listPtr + i) > max ? *(listPtr + i) : max;
    }

    printf("Max element: %d\n", max);

    return 0;
}
