#include <stdio.h>

int gcd(int, int);

// ==== MAIN ====
int main()
{
    int m, n;

    printf("Enter first number: ");
    scanf("%d", &m);

    printf("Enter second number: ");
    scanf("%d", &n);

    printf("\nGCD = %d\n", gcd(m, n));

    return 0;
}

// GCD of two numbers
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}