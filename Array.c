#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int arr[MAX];
int size = 0;

void insert(int d, int pos) {
    if (size == MAX) {
        printf("Array is full, insertion not possible.\n");
        return;
    }
    
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = d;
    size++; 
}

void delete(int pos) {
    if (size == 0) {
        printf("Array is empty, deletion not possible.\n");
        return;
    }

    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; 
}

void display() {
    if (size == 0) {
        printf("The array is empty.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int d, pos, ch, e = 0;
    
    while (e != 4) {
        printf("1.INSERT\n2.DISPLAY\n3.DELETE\n4.EXIT\n");
        printf("CH - ");
        scanf("%d", &ch);
        
        switch (ch) {   
            case 1: {
                printf("INSERTING.....\n");
                printf("Enter the Data: ");
                scanf("%d", &d);
                printf("Enter the Position: ");
                scanf("%d", &pos);
                insert(d, pos);
                printf("No.of.Elements = %d\n", size);
                break;
            }
            case 2: {
                printf("DISPLAYING.....\n");
                display();
                break;
            }    
            case 3: {
                printf("DELETING.....\n");
                printf("Enter the Position: ");
                scanf("%d", &pos);
                delete(pos);
                printf("DELETED!\n");
                break;
            }
            case 4: {
                printf("EXITING.....\n");
                e = 4;
                break;
            }
            default: {
                printf("INVALID CH.....\n");
            }
        }
    }

    return 0;
}
