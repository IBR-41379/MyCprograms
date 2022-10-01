#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} * start;

void create_List(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link=NULL;
    if(start==NULL)
    {
        start=tmp;
        tmp->link=start;
    }
    else
    {
    tmp->link=start->link;
    start->link=tmp;
    start=tmp;
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
    q = start->link;
    do
    {
        printf("%d ", q->info);
        q = q->link;
    }while (q!= start->link);
    printf("\n");
}
void insert_beg(int data)
{
    struct node *tmp;
    tmp=malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start->link;
    start->link=tmp;
}
void insert_pos(int data,int pos)
{
    if(start==NULL)
        return;
    int i=0;
    struct node *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=NULL;
    struct node *q;
    q=start->link;
    while(i<pos-1)
    {
        if(q != NULL)
        q=q->link;   
        i++;
    }
    if(q==start){
        tmp->link=start->link;
        q->link=tmp;
        start=tmp;
    }else{
        tmp->link=q->link;
        q->link=tmp;
    }
}
void delete (int data)
{
    struct node *q, *tmp;
    if (start->link->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return;
    }
    q = start->link;
    while (q->link->link != start)
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
        q->link = start;
        return;
    }
}

void main()
{
    int data, i, n,c=0, choice, pos;
    start = NULL;
    while (choice!=6)
    {
        printf("Press:- \n1 to Create List\n2 to Display\n3 to insert Insert new node at beginning\n4 to Insert new node at said position\n5 to Delete a node\n6 to Quit\n");
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
            display();
            break;
        case 3:
            printf("Enter Data:");
            scanf("%d", &data);
            insert_beg(data);
            break;
        case 4:
            printf("Enter Data and Position:");
            scanf("%d %d", &data, &pos);
            insert_pos(data, pos);
            break;
        case 5:
            printf("Enter Data:");
            scanf("%d", &data);
            delete(data);
            break;
        }
    }
}