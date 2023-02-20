#include <stdio.h>
#include <string.h>
// Function prototype
void sort(char words[][20], int length);

int main(void)
{
    char words[][20] = {"z", "ab","aa","ac","hello", "this", "is", "a", "string", "of", "words", "and", "letters", "to", "be", "sorted"};
    int length = sizeof(words) / sizeof(words[0]);

    printf("Unsorted: ");
    for (int i = 0; i < length; i++)
    {
        printf("%s ", words[i]);
    }

    printf("\n");

    sort(words, length);
    printf("Sorted: ");
    for (int i = 0; i < length; i++)
    {
        printf("%s ", words[i]);
    }
    return 0;
}

// Sort the words in alphabetical order 
void sort(char words[][20], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                char temp[20];
                strcpy(temp, words[j]);
                // Swap the string with the next string
                strcpy(words[j], words[j + 1]);
                // Copy the temp string into the next string
                strcpy(words[j + 1], temp);
            }
        }
    }
}

