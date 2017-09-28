#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>
//Brute force to crack password

int main(int argc, char *argv[])
{
    // let us creat an array containing 52 upper and lower case letters
    char my_array[52];
    if (argc != 2)
    {
        printf("There should and must be one argument provided.\n");
        return (1);
    }
    char *given_pw;
    given_pw = argv[1];   /*get the user's given password*/
    for (int i = 0; i <= 25; i++)
    {
        char low_char = (char)(i + 97);
        my_array[i] = low_char;
    }
    for (int j = 0; j <= 25; j++)
    {
        char up_char = (char)(j + 65);
        my_array[j + 26] = up_char;
    }
    
    
    
    // loop through 1 letter words to check if password exist
    for (int a = 0; a <= 51; a++)
    {
        char guess_str[2];
        guess_str[0] = my_array[a];
        guess_str[1] = '\0';
        char *guess_pw = crypt(guess_str, "50");
        if(strcmp(guess_pw, given_pw) == 0)
        {
            printf("Match found,and the password should be: %s\n", guess_str);
            return (0);
        }
    }
    
    
    
    // A for loop to check second
    for (int a = 0; a <= 51; a++)
    {
        for (int b = 0; b <= 51; b++)
        {
            char guess_str[3];
            guess_str[0] = my_array[a];
            guess_str[1] = my_array[b];
            guess_str[2] = '\0';
            char *guess_pw = crypt(guess_str, "50");
            if(strcmp(guess_pw, given_pw) == 0)
            {
                printf("Match found,and the password should be: %s\n", guess_str);
                return (0);
            }
        }
    }
    
    // a for loop to check 3 letters words
    
    for (int a = 0; a <= 51; a++)
    {
        for (int b = 0; b <= 51; b++)
        {
            for (int c = 0; c <= 51; c++)
            {
                char guess_str[4];
                guess_str[0] = my_array[a];
                guess_str[1] = my_array[b];
                guess_str[2] = my_array[c];
                guess_str[3] = '\0';
                char *guess_pw = crypt(guess_str, "50");
                if(strcmp(guess_pw, given_pw) == 0)
                {
                    printf("Match found,and the password should be: %s\n", guess_str);
                    return (0);
                }
            }
        }
    }
    
    // a for loop to check 4 letter words
    for (int a = 0; a <= 51; a++)
    {
        for (int b = 0; b <= 51; b++)
        {
            for (int c = 0; c <= 51; c++)
            {
                for (int d = 0; d <= 51; d++)
                {
                    char guess_str[5];
                    guess_str[0] = my_array[a];
                    guess_str[1] = my_array[b];
                    guess_str[2] = my_array[c];
                    guess_str[3] = my_array[d];
                    guess_str[4] = '\0';
                    char *guess_pw = crypt(guess_str, "50");
                    if(strcmp(guess_pw, given_pw) == 0)
                    {
                        printf("Match found,and the password should be: %s\n", guess_str);
                        return (0);
                    }
                }
            }
        }
    }
    printf("Sorry, no match found!");
    return (0);
}
