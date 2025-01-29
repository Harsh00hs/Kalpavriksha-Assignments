#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    int power;
    struct node* next;
}node;

node *poly1=NULL;
node *poly2=NULL;

node *result=NULL;

void display(node* head){
    if(head==NULL){
        printf("0");
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
    ptr->next = NULL;

    if(*head==NULL){
        *head=ptr;
        return;
    }

    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
}

void multiplication(node* poly1, node* poly2){
    int coef=0, expo=0;
    node* temp=NULL;
    for(node* i= poly1; i!=NULL; i=i->next){
        for(node* j= poly2; j!=NULL; j=j->next){
            coef=i->data * j->data;
            expo=i->power + j->power;
            insert(&temp, coef, expo);
        }
    }
    for(node* i=temp; i!=NULL; i=i->next){
        int found=0;
        for(node* j=result; j!=NULL; j=j->next){
            if(i->power==j->power){
                j->data += i->data;
                found=1;
                break;
            }
        }

        if (!found) {
            insert(&result, i->data, i->power);
        }
    }

    printf("Resultant List: ");
    display(result);
}

int main(){
    insert(&poly1, 1, 3);
    insert(&poly1, 6, 2);
    insert(&poly1, 11, 1);
    insert(&poly1, 6, 0);

    insert(&poly2, 1, 1);
    insert(&poly2, 4, 0);

    printf("Expression 1: ");
    display(poly1);

    printf("Expression 2: ");
    display(poly2);

    multiplication(poly1, poly2);

    return 0;
}