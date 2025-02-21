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

void display(){
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

node* reverse(node* head, int k){
    node* prev = NULL;
    node* nextNode = NULL;
    node* curr = head;
    int pos = k;
    while(pos != 0 && curr != NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos--;
    }
    if(nextNode){
        node* recAns = reverse(nextNode, k);
        head->next = recAns;
    }
    
    return prev;    
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        insert(arr[i]);
        
    display();
    int k=3;
    
    head = reverse(head, k);
    display();
    return 0;
}