#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head,*temp,*curr,*tail;
void insert(int d,int pos,int c)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("The Memory is not Allocated Properly...");
    }
    else
    {
        new->data=d;
        if(head==NULL || pos==0)
        {
            new->prev=NULL;
            new->next=NULL;
            head=new;
        }
        else if(pos==1)
        {
            new->prev=NULL;
            new->next=head;
            head->prev=new;
            head=new;
        }
        else if(c+2==pos)
        {
            curr=curr->next;
            curr->next=new;
            new->next=NULL;
            new->prev=curr;
        }
        else
        {
            temp=head;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            new->next=temp->next;
            temp->next=new;
            new->prev=temp;
            temp=temp->next;
            temp=temp->next;
            temp->prev=new;
        }
    }
}
void delete(int pos,int c)
{
    temp=head;
    if(head==NULL)
    {
        printf("Deletion is not Possible...");
    }
    else
    {
        if(pos==1)
        {
            head=head->next;
            head->prev=NULL;
        }
        else if(pos==c+1)
        {
            for(int i=1;temp!=NULL && i<pos-1;i++)
            {
                temp=temp->next;
            }temp->next=NULL;
        }
        else
        {
            for(int i=1;temp!=NULL && i<pos-1;i++)
            {
                temp=temp->next;
            }temp->next=temp->next->next;
        }
    }
}
void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("The Node is Empty...\n");
    }
    printf("NULL\t");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("NULL");
    printf("\n");
}
void revdisplay()
{
    tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    printf("NULL\t");
    while(tail!=NULL)
    {
        printf("%d\t",tail->data);
        tail=tail->prev;
    }printf("NULL");
    printf("\n");
}
void main()
{
    int d,pos,ch,e;
    while(e!=4)
    {
        printf("1.INSERT\n2.DISPLAY\n3.DELETING\n4.EXIT\n");
        printf("CH - ");
        scanf("%d",&ch);
        switch(ch)
        {   
            case 1:
                {
                    curr=head;
                    int c=0;
                    while(curr!=NULL)
                    {
                        curr=curr->next;
                        c+=1;
                    }
                    printf("INSERTING.....\n");
                    printf("Enter the Data:");
                    scanf("%d",&d);
                    printf("Enter the Position:");
                    scanf("%d",&pos);
                    if(pos<0 || pos>c+1)
                    {
                        printf("Incorrect Position...\n");
                    }
                    else
                    {
                    insert(d,pos,c);
                    }
                    printf("No.of.Nodes=%d\n",c+1);
                    break;
                }
            case 2:
                {
                    printf("DISPLAYING.....\n");
                    display();
                    printf("REVERSE DISPLAYING.....\n");
                    revdisplay();
                    break;
                }    
            case 3:
                {
                    curr=head;
                    int c=0;
                    while(curr!=NULL)
                    {
                        curr=curr->next;
                        c+=1;
                    }
                    printf("Enter the Position:");
                    scanf("%d",&pos);
                    printf("DELETING.....\nDELETED!\n");
                    if(pos<0 || pos>c+1)
                    {
                        printf("Incorrect Position...\n");
                    }
                    delete(pos,c);
                    break;
                }
            case 4:
                {
                    printf("EXITING.....\n");
                    e=4;
                    break;
                }
            default:
                {
                    printf("INVALID CH.....\n");
                }
        }
    }
}
