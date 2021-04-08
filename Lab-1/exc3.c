#include<stdio.h>
#include<stdlib.h>

void removeElement(int* size, int* ptr, int index)
{
    for(int i=index; i<(*size); i++)
    {
        *(ptr+i) = *(ptr+i+1);
    }
    (*size)--;
}

void removeNegative(int* size, int* ptr)
{
    for(int i=0; i<(*size); i++)
    {
        if(*(ptr+i) < 0)
        {
            removeElement(size, ptr, i);
        }
    }
}

int main()
{
    int size;
    int* sizePtr = &size;
    printf("Size of list: ");
    scanf("%d", sizePtr);

    int *listPtr = (int*) malloc(size * sizeof(int));

    printf("Array elements: ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", listPtr + i);
    }

    removeNegative(sizePtr, listPtr);

    printf("\nElements after deletion: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", *(listPtr + i));
    }
    puts("");

    return 0;
}
