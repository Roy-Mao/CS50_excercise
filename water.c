
#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int n;
    do 
    {
        printf ("Number:");
        n = get_int() ;
    }
    while (n <= 0);
    int b = n * 12;
    printf ("Minutes: %i\n", n);
    printf ("Bottles: %i\n", b);
}