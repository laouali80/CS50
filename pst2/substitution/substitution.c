#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verif_letter(string str);
string encrypt(string str, string KEY);



int main(int argc, string argv[])
{
    string key, plaintext, ciphertext;
    
    if(argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    }
    else if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    key = argv[1];

    plaintext = get_string("Plaintext: ");

    ciphertext = encrypt(plaintext, key);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

int verif_letter(string str)
{
    int i = 0, lengh = 0;

    lengh = strlen(str);

    for(i = 0; i < lengh; i++)
    {
        if(!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z'))
        {
            return 1;
        }
    }

    return 0;
}

string encrypt(string str, string KEY)
{
    int i = 0, lengh = 0;

    lengh = strlen(str);

    for(i = 0; i < lengh; i++)
    {
        if(islower(str[i]))
        {
            str[i] = KEY[str[i] - 97];

            str[i] = tolower(str[i]);
        }
        else if(isupper(str[i]))
        {
            str[i] = KEY[str[i] - 65];

            str[i] = toupper(str[i]);
        }
        else
        {
            str[i] = str[i];
        }
    }

    return str;
}