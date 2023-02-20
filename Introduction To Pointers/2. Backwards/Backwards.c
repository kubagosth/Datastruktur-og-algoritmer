#include <stdio.h>
#include <string.h>
// Function prototype
void reverse(char string[], int length);

int main(void)
{
    char string[] = "Hello world rambuk";
    int length = strlen(string);

    printf("%s \n", string);

    reverse(string, length);
    printf("%s",string);

    return 0;
}

void reverse(char string[], int length)
{
    for (int i = 0; i < length/2; i++)
    {
        char temp = string[i];
        // swap the first character with the last character
        string[i] = string[length - i - 1];
        // swap the last character with the first character
        string[length - i - 1] = temp;
    }
}
