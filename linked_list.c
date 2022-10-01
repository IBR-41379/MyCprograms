#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *start;

void create_List(int data)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if (start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = tmp;
    }
}
void display()
{
    struct node *q;
    if (start == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    q = start;
    while (q != NULL)
    {
        printf("%d ", q->info);
        q = q->link;
    }
    printf("\n");
}

void search(int val)
{
    struct node *q;
    int pos;
    q = start;
    while (q != NULL)
    {
        if (q->info == val)
        {
            printf("Element found at %d position", pos);
            return;
        }
        else
        {
            q = q->link;
            pos++;
        }
        if (q == NULL)
            printf("Element Not Found");
    }
}
void reverse()
{
    struct node *a1, *a2, *a3;
    if (start->link == NULL)
    {
        printf("Only one node\n");
        return;
    }
    a1 = start;
    a2 = a1->link;
    a3 = a2->link;
    a1->link = NULL;
    a2->link = a1;
    while (a3 != NULL)
    {
        a1 = a2;
        a2 = a3;
        a3 = a3->link;
        a2->link = a1;
    }
    start = a2;
}
void sort(int n)
{
    int i, j, tmp;
    struct node *p, *q;
    p = start;
    for (i = 0; i < n - 1; i++)
    {
        q = p->link;
        for (j = i + 1; j < n; j++)
        {
            if (p->info > q->info)
            {
                tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
            q = q->link;
        }
        p = p->link;
    }
}
void insert_beg(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}
void insert_pos(int data, int pos)
{
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 1; i < pos ; i++)
        q = q->link;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = q->link;
    q->link = tmp;
}
void delete (int data)
{
    struct node *q, *tmp;
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return;
    }
    q = start;
    while (q->link->link != NULL)
    {
        if (q->link->info = data)
        {
            tmp = q->link;
            q->link = tmp->link;
            free(tmp);
            return;
        }
        q = q->link;
    }
    if (q->link->info == data)
    {
        tmp = q->link;
        free(tmp);
        q->link = NULL;
        return;
    }
}

void main()
{
    int data, i, n,c=0, choice, pos;
    start = NULL;
    while (choice!=9)
    {
        printf("Press:- \n1 to Create List\n2 to Insert new node at beginning\n3 to Insert new node at said position\n4 to delete\n5 to Search\n6 to Sort\n7 to Reverse\n8 to Display\n9 to Quit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number of elements:");
            scanf("%d", &n);
            printf("Enter the elements:");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                create_List(data);
                c++;
            }
            break;
        case 2:
            printf("Enter Data:");
            scanf("%d", &data);
            insert_beg(data);
            break;
        case 3:
            printf("Enter Data and Position:");
            scanf("%d %d", &data, &pos);
            insert_pos(data, pos);
            break;
        case 4:
            scanf("%d", &data);
            delete (data);
            break;
        case 5:
            scanf("%d", &data);
            search(data);
            break;
        case 6:
            sort(c);
            break;
        case 7:
            reverse();
            break;
        case 8:
            display();
            break;
        }
    }
}