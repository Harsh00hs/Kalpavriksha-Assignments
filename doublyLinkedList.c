#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head=NULL;

void insertAtEnd(int value){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=value;
    ptr->next=NULL;
    
    if(head==NULL){
        ptr->prev=NULL;
        head=ptr;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
}

void insertAtBeginning(int value){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=value;
    ptr->next=head;
    ptr->prev=NULL;
    
    if(head!=NULL)
        head->prev=ptr;

    head=ptr;
}

void insertAtMiddle(int value){
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = NULL;
    ptr->prev = NULL;
    
    if(head==NULL){
        head = ptr;
        return;
    }
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    temp=head;
    for(int i=0; i<count/2-1; i++){
        temp=temp->next;
    }
    ptr->next=temp->next;
    ptr->prev=temp;
    
    if(temp->next!=NULL){
        temp->next->prev=ptr;
    }
    temp->next=ptr;
}

void display(){
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    node* ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void reverse(){
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    
    node* ptr=head;
    while(ptr!=NULL && ptr->next != NULL)
        ptr=ptr->next;
        
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->prev;
    }
    printf("\n");
}

void deleteAtBeginning(){
    if(head==NULL){
        printf("Invalid: List is Empty.\n");
        return;
    }
    node *temp=head;
    head=temp->next;
    free(temp);
}

void deleteAtEnd(){
    if(head==NULL){
        printf("Invalid: List is Empty.\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->prev->next=NULL;
    free(temp);
}

void deleteAtMiddle(){
    if(head==NULL){
        printf("Invalid: List is Empty.\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    int count = 0;
    node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < count/2-1; i++) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    
}

void countItem(){
    node *ptr=head;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    printf("Number of item in list: %d\n", count);
}

int main(){
    int n;
    printf("Enter number of method to be performed: ");
    do {
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("Invalid! Enter between 1 and 100: ");
        }
    } while (n < 1 || n > 100);
    
    int i=0;
    while(i<n){
        printf("1. Insert at end.\n");
        printf("2. Insert at beginning.\n");
        printf("3. Insert at Middle.\n");
        printf("4. Traverse Forward.\n");
        printf("5. Traverse Backward.\n");
        printf("6. Number of items.\n");
        printf("7. Delete the first element.\n");
        printf("8. Delete the last element.\n");
        printf("9. Delete at middle.\n");
        int ch;
        scanf("%d", &ch);
        
        int x;
        
        switch(ch){
            case 1:
                scanf("%d", &x);
                insertAtEnd(x);
                break;
            case 2:
                scanf("%d", &x);
                insertAtBeginning(x);
                break;
            case 3:
                scanf("%d", &x);
                insertAtMiddle(x);
                break;
            case 4:
                display();
                break;
            case 5:
                reverse();
                break;
            case 6:
                countItem();
                break;
            case 7:
                deleteAtBeginning();
                break;
            case 8:
                deleteAtEnd();
                break;
            case 9:
                deleteAtMiddle();
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        i++;
    }
    return 0;
}
