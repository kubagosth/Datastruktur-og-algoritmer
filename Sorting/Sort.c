#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
// Function prototype
void swap(int *a, int *b);
void quickSort(int numbers[], int first, int last);
void selectionSort(int numbers[], int length);
void insertionSort(int numbers[], int length);
void mergeSort(int numbers[],int first,int last, int length);
void print(int numbers[], int length,char string[]);

int main(void)
{
    int numbers[50000];
    for (int i = 0; i < 50000; i++)
    {
        numbers[i] = rand() % 100;
    }
    int length = sizeof(numbers) / sizeof(int);


    //print(numbers, length, "Unsorted: ");
    int input = 0;
    printf("\n\n1. Quick Sort, 2. Selection Sort, 3. Insertion Sort, 4. Merge Sort: ");
    scanf("%i", &input);

    clock_t start, end;
    double time;
    start = clock();

    switch (input)
    {
    case 1:
        quickSort(numbers, 0, length-1);
        break;
    case 2:
        selectionSort(numbers, length);
        break;
    case 3:
        insertionSort(numbers, length);
        break;
    case 4:
        mergeSort(numbers, 0, length-1, length);
        break;
    }

    end = clock();
    time = (double)(end -start) / CLOCKS_PER_SEC;
    
    //print(numbers, length, "Sorted: ");
    printf("\nTime: %f Seconds\n", time);
    return 0;
}
void print(int numbers[],int length,char string[])
{
    printf(string);
    for (int i = 0; i < length; i++)
    {
        printf("%i ", numbers[i]);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int numbers[], int first, int last)
{
    if (first < last)
    {
        int pivot = numbers[last];
        int i = first - 1;
        for (int j = first; j < last; j++)
        {
            if (numbers[j] < pivot)
            {
                i++;
                swap(&numbers[i], &numbers[j]);
            }
        }
        swap(&numbers[i+1], &numbers[last]);
        int pivotIndex = i + 1;
        quickSort(numbers, first, pivotIndex-1);
        quickSort(numbers, pivotIndex+1, last);
    }
}

void selectionSort(int numbers[], int length)
{
    int minIndex;
    for (int i = 0; i < length; i++)
    {
        minIndex = i;
        for (int j = i+1; j < length; j++)
        {
            if (numbers[j] < numbers[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&numbers[minIndex], &numbers[i]);
    }
}
void insertionSort(int numbers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int j = i;
        while (j>0 && numbers[j-1] > numbers[j])
        {
            swap(&numbers[j], &numbers[j-1]);
            j--;
        }
    }
}
void mergeSort(int numbers[],int first, int last, int length)
{
 if(first < last)
 {
    int mid = (first + last) /2;
    mergeSort(numbers, first, mid, length);
    mergeSort(numbers, mid+1, last, length);
    int i = first;
    int j = mid+1;
    int k = 0;
    int *tempArray = (int*)malloc(length * sizeof(int));
    while (i <= mid && j <= last)
    {
        if (numbers[i] < numbers[j])
        {
            tempArray[k] = numbers[i];
            i++;
        }
        else
        {
            tempArray[k] = numbers[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        tempArray[k] = numbers[i];
        i++;
        k++;
    }
    while (j <= last)
    {
        tempArray[k] = numbers[j];
        j++;
        k++;
    }
    for (int i = first; i <= last; i++)
    {
        numbers[i]  = tempArray[i-first];
    }
    free(tempArray);
 }
}