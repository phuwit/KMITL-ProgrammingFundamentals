#include <stdio.h>
int main()
{
    int n, reversedInteger = 0, remainder, originalInteger;
    printf("Enter an integer: ");
    scanf("%d", &n);
    originalInteger = n;
    // reversed integer is stored in variable (#1)
    printf("#1 %d\n", reversedInteger);
    while (n != 0)
    {
        remainder = n % 10;
        reversedInteger = reversedInteger * 10 + remainder;
        n /= 10; //(#2)
        printf("#2 %d\n", reversedInteger);
    }
    // palindrome if orignalInteger and reversedInteger are equal (#3)
    printf("#3 %d\n", reversedInteger);
    if (originalInteger == reversedInteger)
        printf("%d is a palindrome.", originalInteger);
    else
        printf("%d is not a palindrome.", originalInteger);
    return 0;
}

