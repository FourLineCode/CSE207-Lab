#include <stdio.h>

int power(int, int);

// ==== MAIN ====
int main()
{
    int n, p;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Enter power: ");
    scanf("%d", &p);

    printf("\nPower = %d\n", power(n, p));

    return 0;
}

// Power of any number
int power(int n, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return n;

    return n * power(n, p - 1);
}