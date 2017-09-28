#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    int n;
    string user_name;
    do
    {
        user_name = get_string();
    }
    while(user_name == NULL);
    n = strlen(user_name);
    if (user_name[0] != ' ')
    {
        putchar(toupper(user_name[0]));
    }
    for (int i = 0; i <= n; i++)
    {
        int j = i + 1;
        if (j <= n)
        {
            if (user_name[i] == ' ' && user_name[j] != ' ' && user_name[j] != '\0')
            {
                putchar(toupper(user_name[j]));
            }
        }
    }
    printf("\n");
}