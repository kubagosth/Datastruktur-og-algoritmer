#include <stdio.h>
// Function prototype
void sortAsc(int numbers[], int length);
void sortDes(int numbers[], int length);

int main(void)
{
    int numbers[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
    int length = sizeof(numbers) / sizeof(int);

    printf("Unsorted Numbers: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", numbers[i]);
    }

    printf("\n");

    sortAsc(numbers, length);
    printf("Sorted ascending: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", numbers[i]);
    }
    
    sortDes(numbers, length);
    printf("\nSorted descending: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", numbers[i]);
    }
    
    return 0;
}

// sort the numbers in ascending order
void sortAsc(int numbers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                // swap the character at the beginning with the character at the end
                numbers[j] = numbers[j + 1];
                // swap the character at the end with the character at the beginning
                numbers[j + 1] = temp;
            }
        }
    }
}
// sort the numbers in descending order
void sortDes(int numbers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (numbers[j] < numbers[j + 1])
            {
                int temp = numbers[j];
                // swap the character at the beginning with the character at the end
                numbers[j] = numbers[j + 1];
                // swap the character at the end with the character at the beginning
                numbers[j + 1] = temp;
            }   
        }
    }
}