#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;
void insert(int d, int pos) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed...\n");
    } else {
        new->data = d;
        if (head == NULL) { 
            head = new;
            tail = new;
            new->next = head; 
        } else if (pos == 0) {  
            new->next = head;
            head = new;
            tail->next = head; 
        } else { 
            struct node* temp = head;
            for (int i = 1; temp->next != head && i < pos; i++) {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;
            if (temp == tail) { 
                tail = new;
            }
        }
    }
}
void delete(int pos) {
    if (head == NULL) {
        printf("The list is empty...\n");
    } else {
        struct node* temp = head;
        if (pos == 1) {  
            if (head == tail) { 
                free(head);
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                tail->next = head;
                free(temp);
            }
        } else {  
            struct node* prev = NULL;
            for (int i = 1; temp->next != head && i < pos; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == head) {  
                printf("Position out of range...\n");
            } else {
                prev->next = temp->next;
                if (temp == tail) { 
                    tail = prev;
                }
                free(temp);
            }
        }
    }
}
void display() {
    if (head == NULL) {
        printf("The list is empty...\n");
    } else {
        struct node* temp = head;
        do {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}
void main() {
    int ch, data, pos,e;
     while (e != 4){
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert(data, pos);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                delete(pos);
                break;
            case 3:
                printf("Displaying list...\n");
                display();
                break;
            case 4:
                printf("Exiting...\n");
                e=4;
                break;
            default:
                printf("Invalid choice...\n");
        }
    } 
}
