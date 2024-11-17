#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int dta, struct node *head)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = dta;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

struct node *longAdd(struct node *head1, struct node *head2)
{
    struct node *head3 = NULL;
    struct node *temp1 = head1;
    temp1 = reverse(temp1);
    struct node *temp2 = head2;
    temp2 = reverse(temp2);
    int carry = 0;

    while (temp1 != NULL && temp2 != NULL)
    {
        int op1 = 0;
        int op2 = 0;
        if (temp1 != NULL)
        {
            op1 = temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
        {
            op2 = temp2->data;
            temp2 = temp2->next;
        }
        int sum = op1 + op2 + carry;
        carry = sum / 10;
        head3 = create(sum % 10, head3);
    }
    while (temp1 != NULL)
    {
        int sum = temp1->data + carry;
        temp1 = temp1->next;
        carry = sum / 10;
        head3 = create(sum % 10, head3);
    }
    while (temp2 != NULL)
    {
        int sum = temp2->data + carry;
        temp2 = temp2->next;

        carry = sum / 10;
        head3 = create(sum % 10, head3);
    }
    if (carry > 0)
    {
        head3 = create(carry, head3);
    }

    head3 = reverse(head3);
    return head3;
}

void show(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    head1 = create(8, head1);
    head1 = create(9, head1);
    head1 = create(9, head1);
    head1 = create(9, head1);
    printf("Number 1 is: ");
    show(head1);
    printf("\n\n");

    head2 = create(6, head2);
    head2 = create(8, head2);
    head2 = create(9, head2);
    head2 = create(9, head2);
    head2 = create(9, head2);
    printf("Number 2 is: ");
    show(head2);
    printf("\n\n");

    printf("The sum is: ");
    head3 = longAdd(head1, head2);
    show(head3);
    printf("\n");
}