#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



int count_words(string str);
int count_letters(string str);
int count_sentences(string str);


int main(void)
{
   char *text = NULL;
   int words = 0, letters = 0, sentence = 0;
   float formula = 0, avrg_s = 0, avrg_l = 0;

   text = get_string("Text: ");

   letters = count_letters(text);

   words = count_words(text);

   sentence = count_sentences(text);

   avrg_l = (float)letters / (float)words * 100;

   avrg_s = (float)sentence / (float)words * 100;

   formula = round(0.0588 * avrg_l - 0.296 * avrg_s - 15.8);

   if(formula < 1)
   {
        formula = 1;
        printf("Before Grade %.f\n", formula);
   }
   else if(formula < 16)
   {
        printf("Grade %.f\n", formula);
   }
   else
   {
        formula = 16;
        printf("Grade %.f+\n", formula);
   }

    return 0;

}


int count_letters(string str)
{
    int lengh = 0, i = 0, count_l = 0;

    lengh = strlen(str);

    for(i = 0; i < lengh; i++)
    {
        if(islower(str[i]) || isupper(str[i]))
        {
            count_l++;
        }
    }

    return count_l;
}


int count_words(string str)
{
    int lengh = 0, i = 0, count_w = 0;

    lengh = strlen(str);

    if(lengh > 0)
    {
        count_w = 1;
        for(i = 0; i < lengh; i++)
        {
            if(str[i] == 32)
            {
                count_w++;
            }
        }

        return count_w;
    }

    return count_w;
}



int count_sentences(string str)
{
    int lengh = 0, i = 0, count_s = 0;

    lengh = strlen(str);

    if(lengh > 0)
    {
        for(i =0; i < lengh; i++)
        {
            if(str[i] == 46 || str[i] == 33 || str[i] == 63)
            {
                count_s++;
            }
        }

        return count_s;
    }

    return count_s++;
}

