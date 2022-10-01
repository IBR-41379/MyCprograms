#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev,*next;
} *last;
void Create_List(int data)
{
    struct node *tmp,*q;
    q=last;
    tmp=malloc(sizeof(struct node));
    tmp->info=data;
    if(last==NULL)
    {
        last=tmp;
        tmp->prev=last;
        tmp->next=last;
    }
    else
    {
        tmp->next=last->next;
        tmp->prev=last;
        last->next=tmp;
        q->prev=tmp;
        last=tmp;
    }
}
void display()
{
    struct node *q;
    q=last->next;
    while(q!=last)
    {
        printf("%d ",q->info);
        q=q->next;
    }
    printf("%d ",q->info);
}
void main()
{
    int data, i, n,c=0, choice;
    last=NULL;
    while (choice!=3)
    {
        printf("Press:- \n1 to Create List\n2 to Display\n3 to Quit\n");
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
                Create_List(data);
                c++;
            }
            break;
        case 2:
            display();
            break;
        }
    }
}
