#include <stdio.h>
#include <string.h>
// Function prototype
int countWords(char string[]);
int countLetters(char string[]);

int main(void)
{
    char string[] = "hello this is a string of words and letters to be counted";

    int words = countWords(string);
    int letters = countLetters(string);
    
    printf("Words: %i Letters: %i", words, letters);

    return 0;
}

int countWords(char string[])
{
    int words = 0;
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (string[i] == ' ')
        {
            words++;
        }
    }

    return words + 1;
}

int countLetters(char string[])
{
    int letters = 0;
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        if (string[i] != ' ')
        {
            letters++;
        }
    }

    return letters;
}

