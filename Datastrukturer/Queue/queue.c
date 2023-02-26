#include <stdio.h>  
#include <stdlib.h>

struct Node  
{  
    int data;  
    struct Node* next;  
};

struct Node* first = NULL;
struct Node* last = NULL;

void enqueue(int data);
void dequeue();
void printQueue();
void printAllocated();

void runTest()
{
    
    for (int i = 0; i < 10; i++)
        enqueue(i);
    printQueue();
    printAllocated();

    for (int i = 0; i < 5; i++)
        dequeue();
    printQueue();
    printAllocated();

    for (int i = 5; i < 10; i++)
        enqueue(i);
    printQueue();
    printAllocated();

}

int main(void)
{
    runTest();
    return 0;
}

void printAllocated()
{
    struct Node* temp = first;
    while (temp != NULL)
    {
        printf("[ %p ]", temp);
        temp = temp->next;
    }
    printf("\n\n");
}

void enqueue(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = last = newNode;
        return;
    }
    last->next = newNode;
    last = newNode;
}

void dequeue()
{
    struct Node* temp = first;
    if (first == NULL)
    {
        printf("Queue is empty");
        return;
    }
    if (first == last)
    {
        first = last = NULL;
    }
    else
    {
        first = first->next;
    }
    free(temp);
}

void printQueue()
{
    struct Node* temp = first;
    while (temp != NULL)
    {
        printf("[ %i ] -> Current: [ %p ] -> Next: [ %p ] \n", temp->data, temp, temp->next);
        temp = temp->next;
    }
    printf("First -> [ %p ]  Last -> [ %p ]\n", first, last);
}

