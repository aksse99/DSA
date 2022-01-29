// Reverse a linked list using itrative methods
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}
void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *Reverse(struct Node *head)
{
    struct Node *current, *prev, *nex;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        nex = current->next;
        current->next = prev;
        prev = current;
        current = nex;
    }
    head = prev;
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    print(head);
    head = Reverse(head);
    print(head);
}