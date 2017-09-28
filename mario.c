#include <stdio.h>
#include<cs50.h>
int main(void)
{
    int height;
    do
    {
        printf ("Height: ");
        height = get_int();
    }
        while (height > 23 || height < 0);
        for (int i = 1; i <= height; i ++)
        {
            for (int j = 1; j <= height; j++)
            {
                if (j <= height - i)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
            printf("  ");
            for (int n = 1; n <= i; n++)
            {
                printf("#");
            }
        printf("\n");
        }
}