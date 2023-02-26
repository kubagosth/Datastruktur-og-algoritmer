#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insert(int data);
void delete(int data);
void search(int data);
void printList();

int main(void)
{
    for (int i = 0; i < 20; i++)
    {
        insert(i);
    }
    printList();
    for (int i = 0; i < 20; i++)
    {
        delete(i);
    }
    delete(0);
    printList();

    return 0;
}

void insert(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void delete(int data)
{
    struct Node* temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (head == tail)
    {
        head = tail = NULL;
        free(temp);
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp == head)
            {
                head = head->next;
                head->prev = NULL;
                free(temp);
                return;
            }
            if (temp == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
                free(temp);
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Data not found");
}

void search(int data)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data found");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found");
}

void printList()
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("[ %i ] -> Current: [ %p ] -> Next: [ %p ] -> Prev: [ %p ] \n", temp->data, temp, temp->next, temp->prev);
        temp = temp->next;
    }
}

