#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*frt=NULL,*temp=NULL,*rear=NULL,*new;
void enqueue(int d)
{
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("The Memory is not Allocated Properly...\n");
    }
    else{
        new->data=d;
        if(frt==NULL && rear==NULL)
        {
            frt=rear=new;
            new->next=NULL;
        }
        else{
            rear->next=new;
            new->next=NULL;
            rear=new;
        }
        printf("The Data %d is Enqueued to the Queue...\n",d);
    }
}
void dequeue()
{
    if(frt==NULL && rear==NULL){
        printf("The Queue Underflows...\n");
    }
    else{
        temp=frt;
        frt=frt->next;
        printf("The Data %d is Dequeued from the Queue...\n",temp->data);
        free(temp);
    }
}
void display()
{
    if(frt==NULL && rear==NULL){
        printf("The Queue Underflows...\n");
    }
    else{
        temp=frt;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void main()
{
    int data,ch,e;
    while(e!=4)
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("CH - ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the Data:");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Displaying...\n");
                display();
                break;
            case 4:
                printf("Exits..\n");
                e=4;
                break;
            default:
                printf("Invalid Choice...\n");
        }
    }
}
