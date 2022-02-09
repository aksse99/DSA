// Reverse a linked list using recursive function
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
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
    if (head == NULL)
    {
        return;
    }
    print(head->next);
    printf("%d", head->data);
}
struct Node *reverse(struct Node *h)
{
    if (h->next == NULL)
    {
        head = h;
        return head;
    }
    reverse(h->next);
    h->next->next = h;
    h->next = NULL;
}

int main()
{
    head = NULL;
    head = insert(head, 0);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    print(head);
    head = reverse(head);
    print(head);
}
