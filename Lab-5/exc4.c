#include <stdio.h>

int reverse(int);

// ==== MAIN ====
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (reverse(n) == n)
    {
        printf("\nPalindrome\n");
        return 0;
    }
    printf("\nNot Palindrome\n");

    return 0;
}

// Reverse a number
int reverse(int n)
{
    static int rev = 0;

    if (n == 0)
        return rev;

    rev = (rev * 10) + n % 10;
    return reverse(n / 10);
}