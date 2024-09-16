#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

void insert(int d, int pos, int c) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed...\n");
    } else {
        new->data = d;
        if (head == NULL) {
            head = new;
            tail = new;
            new->next = head;
            new->prev = tail;
        } else if (pos == 1) {
            new->next = head;
            new->prev = tail;
            head->prev = new;
            tail->next = new;
            head = new;
        } else if (pos == c + 1) {
            new->prev = tail;
            new->next = head;
            tail->next = new;
            head->prev = new;
            tail = new;
        } else {
            struct node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            new->next = temp->next;
            new->prev = temp;
            temp->next->prev = new;
            temp->next = new;
        }
    }
}

void delete(int pos, int c) {
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
                head->prev = tail;
                tail->next = head;
                free(temp);
            }
        } else if (pos == c) {
            temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            free(temp);
        } else {
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}

void display() {
    if (head == NULL) {
        printf("The list is empty...\n");
    } else {
        struct node* temp = head;
        printf("NULL <-> ");
        do {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("NULL\n");
    }
}

void revdisplay() {
    if (tail == NULL) {
        printf("The list is empty...\n");
    } else {
        struct node* temp = tail;
        printf("NULL <-> ");
        do {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        } while (temp != tail);
        printf("NULL\n");
    }
}

int main() {
    int d, pos, ch, e = 0;

    while (e != 4) {
        printf("1.INSERT\n2.DISPLAY\n3.DELETE\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                struct node* curr = head;
                int c = 0;
                while (curr != NULL && curr->next != head) {
                    curr = curr->next;
                    c++;
                }
                if (head != NULL) c++;

                printf("INSERTING...\n");
                printf("Enter the data: ");
                scanf("%d", &d);
                printf("Enter the position: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > c + 1) {
                    printf("Invalid position...\n");
                } else {
                    insert(d, pos, c);
                }
                break;
            }
            case 2: {
                printf("DISPLAYING...\n");
                display();
                printf("REVERSE DISPLAYING...\n");
                revdisplay();
                break;
            }
            case 3: {
                struct node* curr = head;
                int c = 0;
                while (curr != NULL && curr->next != head) {
                    curr = curr->next;
                    c++;
                }
                if (head != NULL) c++;

                printf("DELETING...\n");
                printf("Enter the position: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > c) {
                    printf("Invalid position...\n");
                } else {
                    delete(pos, c);
                }
                break;
            }
            case 4:
                printf("EXITING...\n");
                e = 4;
                break;
            default:
                printf("INVALID CHOICE...\n");
        }
    }

    return 0;
}
