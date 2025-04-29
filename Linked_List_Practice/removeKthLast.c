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

void removeKth(int k){
    node* temp=head;
    int count=0;
    while(temp){
        ++count;
        temp=temp->next;
    }
    // printf("%d\n", count);
    int pos=count-k;
    // printf("%d\n", pos);
    
    node* ptr=head;
    if(pos==1){
        printf("%d", ptr->data);
        head=head->next;
        free(ptr);
    }
    
    for(int i=1; i<pos; i++){
        ptr=ptr->next;
    }
    
    node* p;
    p=ptr->next;
    ptr->next=p->next;
    printf("%d\n", p->data);
    p->next=NULL;
    free(p);
}

int main(){
    int arr[]={1,2,3,4,5,6};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        insert(arr[i]);
        
    display();
    int k=4;
    removeKth(k);
    display();
    return 0;
}