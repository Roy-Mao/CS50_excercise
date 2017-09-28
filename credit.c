#include <stdio.h>
#include <cs50.h>
int numPlaces(int n);
int main(void)
{
    long long num, add1, add2;
    int dsumadd = 0, sumadd = 0;
    do
    {
        printf("Number: ");
        num = GetLongLong();
    }
    while (num <= 0);
    for (add1 = num; add1 > 0; add1 /= 100)
    {
        int lastdigit = add1 % 10;
        sumadd += lastdigit;
    }
    for (add2 = num / 10; add2 > 0; add2 /= 100)
    {
        int lastdigit2 = add2 % 10;
        int doubledigit = lastdigit2 * 2;
        if (doubledigit > 9)
        {
            int together = doubledigit % 10 + 1;
            dsumadd += together;
        }
        else
        {
            dsumadd += doubledigit;
        }
    }
    int fsum = dsumadd + sumadd;
    if (fsum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if ((num >= 340000000000000 && num <= 349999999999999) || (num >= 370000000000000 && num <= 379999999999999))
        {
            printf("AMEX\n");
        }
        else if ((num >= 5100000000000000 && num <= 5599999999999999))
        {
            printf("MASTERCARD\n");
        }
        else if ((num >= 4000000000000 && num <= 4999999999999) || (num >= 4000000000000000 && num <= 4999999999999999))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}