#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*top;

void push(int data)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->link = top;
    top = tmp;
}
int pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
    struct node *tmp = top;
    top = tmp->link;
    int a = tmp->data;
    free(tmp);
    return a;
    }
}
void display()
{
    if(top == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        struct node *q = top;
        printf("STACK \n");
        while(q!=NULL)
        {
            printf(" %d\n",q->data);
            q=q->link;
        }
    }
}

void main()
{
    top = NULL;
    int a,data,c;
    printf("Menu \n 1:Push to stack \n 2:Pop from Stack \n 3:Display the current stack \n 4:Exit");
    while(1)
    {
        printf("\n Your Choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter element to push:");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("The popped element is: %d",pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:printf("Invalid Choice");
        }
    }
}