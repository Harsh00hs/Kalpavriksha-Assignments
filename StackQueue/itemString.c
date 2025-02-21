#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef struct node{
    char name[256];
    int price;
    struct node* next;
}node;

node*head=NULL;

void input(char name[], int price){
    node* ptr=(node*)malloc(sizeof(node));
    strcpy(ptr->name, name);
    ptr->price=price;
    ptr->next=head;
    head=ptr;
}

void list(){
    if(getchar()!='\n'){
        return;
    }
    if(head==NULL){
        printf("No item present\n");
        return;
    }
    node* curr=head;
    while(curr){
        printf("%s %d\n", curr->name, curr->price);
        curr=curr->next;
    }
}

void update(char name[], int price){
    node* curr=head;
    while(curr){
        if(strcmp(name, curr->name)==0){
            curr->price=price;
            return;
        }
        curr=curr->next;
    }
    if(curr==NULL){
        printf("Item %s not found\n", name);
    }
}

void delete(char name[]){
    node* curr=head;
    node* prev=NULL;
    while(curr){
        if(strcmp(curr->name, name)==0){
            if(prev==NULL){
                head=curr->next;
            }else{
                prev->next=curr->next;
            }
            printf("Item %s deleted.\n", curr->name);
            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        printf("no item present\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char str[256];
    char name[256];
    int price;
    while(n--){
        scanf("%s", str);
        if(strcmp(str,"INPUT")==0){
            scanf("%s", name);
            scanf("%d", &price);
            
            input(name, price);
        }
        else if(strcmp(str, "REMOVE")==0){
            scanf("%s", name);
            
            delete(name);
        }
        else if(strcmp(str, "LIST")==0){
            list();
        }
        else if(strcmp(str, "UPDATE")==0){
            scanf("%s", name);
            scanf("%d", &price);
            
            update(name, price);
        }
        else{
            printf("Invalid\n");
        }
    }

    return 0;
}