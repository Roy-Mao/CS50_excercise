#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char *argv[] )
{
    /* check if there is only one argument provided*/
    if (argc != 2)
    {
        printf("There should and must be one argument provided.\n");
        return (1);
    }
    /* check if the key only contains legal charactor and no space included*/
    string key = argv[1];
    int length_key = strlen(key);
    for (int i = 0; key[i]; i++)
    {
        key[i] = tolower(key[i]);
    }
    for (int i = 0; i <= length_key - 1; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Your words contain illegal char.\n");
            return (1);
        }
    }
    /* ask user for plaintext if the key is valid*/
    printf("plaintext: ");
    string user_input = get_string();
    int length_user = strlen(user_input);
    for (int i = 0; i < length_user; i += length_key)
    {
        for(int j = 0; j < length_key; j++)
            {
                int user_input_index = i + j;
                char c = key[j];
                int key_as_int = (int)c - 97;
                while ((user_input_index <= length_user) && (!isalpha(user_input[user_input_index])))
                {
                    user_input_index += 1;
                    i += 1;
                }
                int char_to_int = (int)user_input[user_input_index];
                int final_int = char_to_int + key_as_int;
                if (char_to_int >= 65 && char_to_int <= 90)
                {
                    if (final_int >= 91)
                    {
                        final_int = final_int - 91 + 65;
                        user_input[user_input_index] = (char)final_int;
                    }
                    else
                    {
                        user_input[user_input_index] = (char)final_int;
                    }
                }
                if (char_to_int >= 97 && char_to_int <= 122)
                {
                    if (final_int >= 123)
                    {
                        final_int = final_int - 123 + 97;
                        user_input[user_input_index] = (char)final_int;
                    }
                    else
                    {
                        user_input[user_input_index] = (char)final_int;
                    }
                }
                
            }
    }
    printf ("ciphertext: %s\n", user_input);
    return (0);
}