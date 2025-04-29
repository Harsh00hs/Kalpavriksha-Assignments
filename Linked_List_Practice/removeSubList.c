#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;
node* sub=NULL;

void insert(node** head, int value){
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=value;
    ptr->next=NULL;

    if(*head==NULL){
        *head=ptr;
        return;
    }

    node *temp=*head;
    while(temp->next!=NULL)
        temp=temp->next;
    
    temp->next=ptr;
}

void display(node* head){
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    node *ptr = head;

    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void removeSublist(){
    node* ptr=head;
    node* p=sub;

    while(ptr != NULL && ptr->next!=NULL){
        if(ptr->next->data==p->data){
            node* temp=ptr->next;
            p=sub;
            while(p!=NULL && temp!=NULL){
                if(p->data!=temp->data){
                    break;
                }
                p=p->next;
                temp=temp->next;
            }
            if(p==NULL){
                ptr->next=temp;
                return;
            }
        }
        ptr=ptr->next;
    }
}

int main(){

    int n, m;
    printf("Enter length of main list: ");
    scanf("%d", &n);

    int val;
    for(int i=0; i<n; i++){
        scanf("%d", &val);
        insert(&head, val);
    }


    printf("Enter length of sub list: ");
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        scanf("%d", &val);
        insert(&sub, val);
    }

    printf("Main list: ");
    display(head);
    printf("\n");

    printf("Sub list: ");
    display(sub);

    removeSublist();

    display(head);
    return 0;
}
