#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    int power;
    struct node* next;
}node;

node* poly1=NULL;
node* poly2=NULL;

node* result=NULL;

void display(node* head){
    if(head==NULL){
        printf("List is empty.");
        return;
    }

    node* curr=head;
    while(curr!=NULL){
        printf("%dx^%d", curr->data, curr->power);
        if(curr->next!=NULL)
            printf("+");

        curr=curr->next;
    }
    printf("\n");
}

void insert(node** head, int coef, int expo){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=coef;
    ptr->power=expo;
    ptr->next=NULL;

    if(*head==NULL){
        *head=ptr;
        return;
    }

    node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=ptr;
}

void addition(node* poly1, node* poly2){
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->power == poly2->power){
            int coef = poly1->data + poly2->data;
            insert(&result, coef, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }else if(poly1->power > poly2->power){
            insert(&result, poly1->data, poly1->power);
            poly1 = poly1->next;
        }else{
            insert(&result, poly2->data, poly2->power);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(&result, poly1->data, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(&result, poly2->data, poly2->power);
        poly2 = poly2->next;
    }

    printf("Resultant Expression: ");
    display(result);
}

int main(){
    insert(&poly1, 5, 3);
    insert(&poly1, 7, 2);
    insert(&poly1, 4, 1);
    insert(&poly1, 9, 0);

    insert(&poly2, 3, 2);
    insert(&poly2, 6, 0);
    insert(&poly2, 8, -1);

    printf("Expression 1: ");
    display(poly1);

    printf("Expression 2: ");
    display(poly2);

    addition(poly1, poly2);

    return 0;
}
