#include <stdio.h>
#include <stdlib.h>

void print(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int m;
    scanf("%d", &m);

    int *list1 = (int *)malloc(m * sizeof(int));
    int *list2 = (int *)malloc(m * sizeof(int));
    int *list3 = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        scanf("%d", &list1[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &list2[i]);
    for (int i = 0; i < m; i++)
        list3[i] = list1[i] > list2[i] ? list1[i] : list2[i];

    // print(list1, m);
    // print(list2, m);
    print(list3, m);
}