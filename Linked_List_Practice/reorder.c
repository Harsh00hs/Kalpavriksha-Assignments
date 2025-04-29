#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node *next;
} node;

node* head = NULL;

void insert(int x){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=NULL;
    
    if(head==NULL){
        head=ptr;
        return;
    }
    
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
}

void display(node* head){
    if (head == NULL){
        printf("List is empty.\n");
        return;
    }
    node* curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

node* reverse(node* sec){
    node* prev=NULL;
    node* next=NULL;
    node* ptr=sec;
    
    while(ptr!=NULL){
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    return prev;
}

void reorder(){
    node* temp=head;
    int count=0;
    while(temp){
        ++count;
        temp=temp->next;
    }
    // printf("%d", count);
    int mid=count/2;
    // printf("%d", mid);
    
    node* first = head;
    node* flast= NULL;
    
    int i=0;
    temp=head;
    while(i<mid){
        i++;
        flast=temp;
        temp=temp->next;
    }
    flast->next=NULL;
    display(first);
    
    node* sec=temp;
    sec = reverse(sec);
    display(sec);
    
    node* result=(node*)malloc(sizeof(node));
    node* current = result;
    
    while(first !=NULL || sec !=NULL){
        if(first!=NULL){
            current->next=first;
            current=current->next;
            first=first->next;
        }
        if(sec!=NULL){
            current->next=sec;
            current=current->next;
            sec=sec->next;
        }
    }
    head=result->next;
    free(result);
}

int main(){
    int arr[]={1,2,3,4,5, 6, 7};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        insert(arr[i]);
        
    display(head);
    
    reorder();
    display(head);
    return 0;
}