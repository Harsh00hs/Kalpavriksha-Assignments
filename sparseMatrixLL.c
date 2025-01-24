#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int row;
    int col;
    int value;
    struct node* next;
}node;

node* head = NULL;

void addNode(int row, int col, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printSparseMatrix(int rows, int cols) {
    node* temp = head;
    printf("Sparse Matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (temp != NULL && temp->row == i && temp->col == j) {
                printf("%d ", temp->value);
                temp = temp->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void freeList() {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int rows = 5, cols = 5;
    
    addNode(0, 1, 5);
    addNode(1, 4, 8);
    addNode(2, 3, 2);
    addNode(3, 1, 6);
    addNode(4, 4, 1);
    
    printSparseMatrix(rows, cols);

    freeList();
    return 0;
}
