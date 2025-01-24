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

void display(){
    node *curr=head;
    while(curr!=NULL){
        printf("%d ", curr->data);
        curr=curr->next;
    }
    printf("\n");
}

void removeElement(int pos){
    node* ptr = head;
    if (pos == 1) {
        head = head->next;
        free(ptr);
        return;
    }
    for(int i=1; i<pos-1; i++){
        ptr=ptr->next;
    }
    
    node* ptr2 = ptr->next;
    ptr->next=ptr2->next;
    free(ptr2);
}

int main() {
    int arr[]={1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    
    for(int i=0; i<n; i++){
        insert(arr[i]);
    }
    
    display();
    
    int i;
    printf("Enter the index to delete: ");
    do {
        scanf("%d", &i);
        if (i < 1 || i > n) {
            printf("Invalid! Enter between 1 and %d: ", n);
        }
    } while (i < 1 || i > n);
    
    removeElement(i);
    
    display();
    return 0;
}
