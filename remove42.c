// Online C compiler to run C program online
#include <stdio.h>
#include "stdlib.h"

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;

void insert(int value){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=value;
    ptr->next=NULL;
    
    if(head==NULL){
        head=ptr;
        return;
    }
    
    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=ptr;
}

void remove42(){
    node* ptr = head;
    node* prev = NULL;

    while(ptr != NULL){
        if(ptr->data == 42){
            if(prev == NULL){
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            node* temp = ptr;
            ptr = ptr->next;
            free(temp);
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
}

void display(){
    node *curr=head;
    while(curr!=NULL){
        printf("%d ", curr->data);
        curr=curr->next;
    }
}

int main() {
    insert(10);
    insert(42);
    insert(30);
    insert(42);
    insert(50);
    insert(70);
    insert(42);
    insert(93);
    insert(42);
    insert(65);

    remove42();
    
    display();
    return 0;
}
