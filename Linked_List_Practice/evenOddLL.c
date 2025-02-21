// Online C compiler to run C program online
#include <stdio.h>
#include "stdlib.h"

typedef struct node{
    int data;
    struct node* next;
}node;

node *head=NULL;
node *evenodd=NULL;

// void display(node **head);

void insert(node **head, int value){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=value;
    ptr->next=NULL;
    
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

void display(node **head){
    node *temp=*head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

void even(){
    node*ptr=head;
    
    while(ptr!=NULL){
        if(ptr->data%2==0){
            insert(&evenodd, ptr->data);
        }
            ptr=ptr->next;
    }
}

void odd(){
    node*ptr=head;
    
    while(ptr!=NULL){
        if(ptr->data%2!=0){
            insert(&evenodd, ptr->data);
        }
            ptr=ptr->next;
    }
}

void evenoddconvert(){
    even();
    odd();
    display(&evenodd);
}

int main() {
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    
    // display(&head);

    evenoddconvert();
    
    return 0;
}