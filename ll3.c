//Linked list deletion at nth position
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
void insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}
void print()
{
    struct node *temp = head;
    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete (int n)
{

    struct node *temp1 = head;

    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            temp1 = temp1->next;
        }
        struct node *temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}
int main()
{
    head = NULL;

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    delete (3);
    delete (1);
    print();
}