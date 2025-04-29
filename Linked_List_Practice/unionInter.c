#include <stdio.h>
#include "stdlib.h"

typedef struct node{
    int data;
    struct node* next;
}node;

node* list1=NULL;
node* list2=NULL;

node* unique=NULL;
node* intersect=NULL;

void insert(node** head, int val){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=val;
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

void display(node* head){
    if(head==NULL){
        printf("0\n");
        return;
    }

    node* curr=head;
    while(curr!=NULL){
        printf("%d", curr->data);
        if(curr->next) 
            printf("->");
        curr=curr->next;
    }
    printf("\n");
}

int checker(node* unique, int value){
    node* temp=unique;
    while(temp){
        if(temp->data==value)
            return 1;
        temp=temp->next;
    }
    return 0;
}

void uni(node* i, node* j){
    while(i){
        insert(&unique, i->data);
        i=i->next;
    }
    while(j){
        if(!checker(unique, j->data))
            insert(&unique, j->data);
        j=j->next;
    }
}

void inter(node* i, node* j){
    while(i!=NULL){
        if(checker(j, i->data))
            insert(&intersect, i->data);
        i=i->next;
    }
}

void unionIntersect(){
    node *i=list1;
    node *j=list2;

    uni(i, j);
    inter(i, j);
    
    display(unique);
    display(intersect);
}

int main(){
    insert(&list1, 1);
    insert(&list1, 3);
    insert(&list1, 4);
    insert(&list1, 5);
    insert(&list1, 17);
    
    insert(&list2, 4);
    insert(&list2, 2);
    insert(&list2, 5);
    insert(&list2, 1);

    display(list1);
    display(list2);

    unionIntersect();
    return 0;
}