#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev,*next;
    int info;
} *start;
void createlist(int data)
{
    struct node *tmp,*q;
    tmp=malloc(sizeof(struct node));
    tmp->info=data;
    tmp->next=NULL;
    if(start==NULL)
    {
        tmp->prev=NULL;
        start=tmp;
    }
    else
    {
        q=start;
        while (q->next != NULL)
            q = q->next;
        q->next=tmp;
        tmp->prev=q;
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
        q=start;
        while (q != NULL)
        {
            printf("%d ", q->info);
            q = q->next;
        }
        printf("\n");
    }
void insert_beg(int data)
{
    struct node *tmp;
    tmp=malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=start;
    start->prev=tmp;
    start=tmp;
}
void insert_pos(int data,int pos)
{
    struct node *tmp,*q;
    q=start;
    tmp=malloc(sizeof(struct node));
    for(int i=1;i<pos;i++)
        q=q->next;
    tmp->info=data;
    tmp->prev=q;
    tmp->next=q->next;
    tmp->next->prev=tmp;
    q->next=tmp;
}
void delete(int data)
{
    struct node *tmp,*q;
    if(start->info==data)
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        free(tmp);
        return;
    }
    q=start;
    while(q->next->next!=NULL)
    {
        if(q->next->info==data)
        {
            tmp=q->next;
            q->next=tmp->next;
            tmp->next->prev=q;
            free(tmp);
            return;
        }
        q=q->next;
        if(q->next->info==data)
        {
            tmp=q->next;
            q->next=NULL;
            free(tmp);
            return;
        }
    }
    
}

void main()
{
    int data, i, n,c=0, choice, pos;
    start = NULL;
    while (choice!=6)
    {
        printf("Press:- \n1 to Create List\n2 to Insert new node at beginning\n3 to Insert new node at said position\n4 to Delete\n5 to Display\n6 to Quit\n");
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
                createlist(data);
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
            printf("Enter Data:");
            scanf("%d", &data);
            delete(data);
            break;
        case 5:
            display();
            break;
        }
    }
}