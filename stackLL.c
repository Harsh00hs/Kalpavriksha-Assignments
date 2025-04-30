// Online C compiler to run C program online
#include <stdio.h>
#include "stdlib.h"

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;

void push(){
    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);
    node* ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("Memory Allocation Failed so can't push\n");
        return;
    }
    ptr->data=val;
    ptr->next=head;
    head=ptr;
}

void pop(){
    if(head==NULL){
        printf("Underflowed");
        return;
    }
    printf("Popped Element: %d\n", head->data);
    node *ptr=head;
    head=head->next;
    free(ptr);
}

void peek(){
    if(head==NULL){
        printf("List is Empty.");
        return;
    }
    printf("The elements in list: ");
    
    node *curr=head;
    while(curr!=NULL){
        printf("%d ", curr->data);
        curr=curr->next;
    }
    printf("\n");
}

int main() {
    int ch;
    printf("Choices :-\n\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Exit");
    
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                return 0;
            default:
                printf("Check the choices given nothing else.");
                return 0;
        }
    }

    return 0;
}
