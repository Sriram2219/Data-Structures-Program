#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head,*temp,*curr;
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
        if(pos==1 || head==NULL)
        {
            new->next=head;
            head=new;
        }
        else if(c+2==pos)
        {
            curr=curr->next;
            curr->next=new;
            new->next=NULL;
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
        }
    }
}
void delete()
{
    if(head==NULL)
    {
        printf("Deletion is not Possible...");
    }
    else
    {
        head=head->next;
    }
}
void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("The Node is Empty...\n");
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("\n");
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
                    insert(d,pos,c);
                    printf("No.of.Nodes=%d\n",c+1);
                    break;
                }
            case 2:
                {
                    printf("DISPLAYING.....\n");
                    display();
                    break;
                }    
            case 3:
                {
                    printf("DELETING.....\nDELETED!\n");
                    delete(pos);
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