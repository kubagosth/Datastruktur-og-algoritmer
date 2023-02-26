#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data);
void pop();
void printStack();
void printAllAllocated();

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }
    printStack();
    printAllAllocated();
    for (int i = 0; i < 5; i++)
    {
        pop();
    }
    printStack();
    printAllAllocated();
    for (int i = 5; i < 10; i++)
    {
        push(i);
    }
    printStack();
    printAllAllocated();
    
    return 0;
}
void printAllAllocated()
{
    struct Node* temp = top;
    while(temp != NULL)
    {
        printf("[ %p ]",temp);
        temp = temp->next;
    }
    printf("\n\n");
}

void push(int data)
{    
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct Node* temp = top;
    if (top == NULL)
    {
        printf("Stack is empty");
        return;
    }
    top = top->next;
    free(temp);
}

void printStack()
{
    struct Node* temp = top;
    while (temp != NULL)
    {
        printf("[ %i ] -> Current: [ %p ] -> Next: [ %p ] \n", temp->data, temp, temp->next);
        temp = temp->next;
    }
    printf("\n");
}
