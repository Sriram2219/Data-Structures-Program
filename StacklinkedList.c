#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head,*temp;
void push(int d)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("The Memory is not Allocated Properly.");
    }
    else
    {
        temp=head;
        new->data=d;
        if(head==NULL)
        {
            new->next=NULL;
            head=new;
        }
        else
        {
            new->next=head;
            head=new;
        }
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("Pop is not possible because the node is empty...\n");
    }
    else
    {
        head=head->next;
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("\n");
}
void main()
{
    int d,e,ch;
    while(e!=4)
    {
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the Data:");
                scanf("%d",&d);
                push(d);
                break;
            case 2:
                printf("The Data is Popped..\n");
                pop();
                break;
            case 3:
                printf("Display...\n");
                display();
                break;
            case 4:
                printf("Exiting");
                e=4;
                break;
            default:
                printf("Invalid Choice..\n");
        }
    }
}