#include <stdio.h>
#include "stdlib.h"
#define max 100

typedef struct node{
    int item;
    int quantity;
    struct node* next;
}node;

node* head=NULL;

void insert(int item, int quantity){
    node* curr=head;
    while(curr){
        if(curr->item==item){
            curr->quantity+=quantity;
            return;
        }
        curr=curr->next;
    }
    
    node* ptr=(node*)malloc(sizeof(node));
    ptr->item=item;
    ptr->quantity=quantity;
    ptr->next=head;
    head=ptr;
}

void display(){
    if(head==NULL){
        printf("No item present.\n");
    }else{
        node* curr= head;
        while(curr){
            printf("%d:%d ", curr->item, curr->quantity);
            curr=curr->next;
        }
        printf("\n");
    }
}

void update(int item, int quantity){
    if(head==NULL){
        printf("item not found\n");
    }else{
        node* curr=head;
        while(curr){
            if(curr->item==item){
                curr->quantity=quantity;
                return;
            }
            curr=curr->next;
        }
        if(curr==NULL)
            printf("item not found\n");
    }
}

void query(int item){
    if(head==NULL){
        printf("item not found\n");
    }else{
        node* curr=head;
        while(curr){
            if(curr->item==item){
                printf("%d\n", curr->quantity);
                return;
            }
            curr=curr->next;
        }
        if(curr==NULL)
            printf("item not found\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int ch;
    int item, quantity;
    
    while(n--!=0){
        scanf("%d", &ch);
        switch(ch){
            case 1:
                scanf("%d", &item);
                scanf("%d", &quantity);
                insert(item, quantity);
                break;
            case 2:
                scanf("%d", &item);
                scanf("%d", &quantity);
                update(item, quantity);
                break;
            case 3:
                display();
                break;
            case 4:
                scanf("%d", &item);
                query(item);
                break;
            default:
                printf("Invalid\n");
                break;
        }
    }

    return 0;
}