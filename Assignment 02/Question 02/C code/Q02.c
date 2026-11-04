/*
Program: Amicable Pairs Finder
Programmer: Abdul Wasy (26K-0023)
Dept: BSAI - 1A
Course: Programming Fundamentals
Instructor: Sir Syed Farooq Zaidi
Dated: October 28, 2026
*/

#include <stdio.h>

// Returns the sum of the proper divisors of x (all divisors except x itself)
int sumOfDivisors(int x)
{
    int i;
    int sum = 0;

    // no proper divisor of x is larger than x / 2
    for (i = 1; i <= x / 2; i++)
    {
        if (x % i == 0)             // i divides x exactly
        {
            sum = sum + i;
        }
    }
    return sum;
}

int main()
{
    int n;                          // upper limit
    int a, b;                       // a candidate pair
    int count = 0;                  // number of pairs found

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Amicable pairs up to %d:\n", n);

    for (a = 2; a <= n; a++)
    {
        b = sumOfDivisors(a);       // sum of proper divisors of a

        // b > a  -> numbers are different and each pair is shown once (smaller first)
        // b <= n -> both numbers must be within the limit
        // sumOfDivisors(b) == a -> b's divisors add back to a
        if (b > a && b <= n && sumOfDivisors(b) == a)
        {
            printf("(%d, %d)\n", a, b);
            count++;
        }
    }

    if (count == 0)
    {
        printf("No amicable pairs found up to %d.\n", n);
    }
    else
    {
        printf("Total pairs: %d\n", count);
    }

    return 0;
}

