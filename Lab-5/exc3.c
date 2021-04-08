#include <stdio.h>

int lcm(int, int);

// ==== MAIN ====
int main()
{
    int m, n;

    printf("Enter first number: ");
    scanf("%d", &m);

    printf("Enter second number: ");
    scanf("%d", &n);

    printf("\nLCM = %d\n", lcm(m, n));

    return 0;
}

// LCM of two numbers
int lcm(int m, int n)
{
    static int temp = 0;
    temp += m > n ? m : n;

    if (temp % m == 0 && temp % n == 0)
    {
        return temp;
    }
    return lcm(m, n);
}