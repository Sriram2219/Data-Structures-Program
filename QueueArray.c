#include<stdio.h>
#define max 5
int front=-1;
int rear=-1;
int a[max];
void enqueue(int d)
{
    if(rear==max-1)
    {
        printf("Queue Overflows...\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        a[rear]=d;
    }
    else
    {
        rear++;
        a[rear]=d;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Underflows...\n");
    }
    else
    {
        front+=1;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Underflows...\n");
    }    
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",a[i]);
        }printf("\n");
    }
}
void main()
{
    int d,ch,e;
    while(e!=4)
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("Choice - ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("ENQUEUED...\n");
                printf("Enter the Data:");
                scanf("%d",&d);
                enqueue(d);
                break;
            case 2:
                printf("DEQUEUED...\n");
                dequeue();
                break;
            case 3:
                printf("DISPLAYING...\n");
                display();
                break;
            case 4:
                printf("EXITS...\n");
                e=4;
                break;
            default:
                printf("INVALID CHOICE\n");
        }
    }
}