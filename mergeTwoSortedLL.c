#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head1=NULL;
node* head2=NULL;
node* mergedHead = NULL;

void insert(node** head, int data){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;

    if(*head==NULL)    {
        *head=ptr;
        return;
    }

    node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = ptr;
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

void merge(node* head1, node* head2){
    node* dummy = (node*)malloc(sizeof(node));
    node* tail = dummy;
    
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    mergedHead = dummy->next;
    free(dummy);
}

int main(){
    insert(&head1, 1);
    insert(&head1, 2);
    insert(&head1, 5);
    insert(&head1, 8);
    insert(&head2, 2);
    insert(&head2, 3);
    insert(&head2, 7);
    insert(&head2, 9);

    printf("List 1: ");
    display(head1);
    printf("List 2: ");
    display(head2);
    
    merge(head1, head2);

    printf("Merged List: ");
    display(mergedHead);    
    
    return 0;
}
