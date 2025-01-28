// Problem Statement: Sort and Rotate a Linked List Around a Given Value

// You are given a singly linked list and an integer value k. Your task is to solve the following two operations:

// 1. Sort the linked list in ascending order.
// 2. Rotate the linked list such that the node containing the value k becomes the new head of the list. After rotation, the nodes that come after the node containing k should follow in the list, maintaining the original order, and the nodes before k should be appended to the end of the list.

// Input:
// - A singly linked list where each node contains an integer value.
// - An integer value k that determines where the rotation happens.

// Output:
// - Return the head of the modified linked list after performing both sorting and rotating operations.

// Constraints:
// - The linked list contains n nodes, where 1 <= n <= 10^5.
// - Each node in the linked list contains an integer value, and k is guaranteed to be present in the linked list.
// - The value k will be a valid integer in the linked list.

// Example:-
// Input: head = [4, 2, 3, 1, 5]
//        k = 3
// Output:[3, 4, 5, 1, 2]

// Explanation:

// - After sorting the linked list, the list becomes: [1, 2, 3, 4, 5].
// - After rotating the list around the node with value 3, the new head becomes 3, and the final list is [3, 4, 5, 1, 2].

#include "stdio.h"
#include "stdlib.h"

int isnum(char c){
    return (c>='0' && c<='9');
}

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;

void insert(int value){
    node *ptr=(node*)malloc(sizeof(node));
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

void parseString(char str[]){
    int negative=0;
    int i=0;
    int temp;
    
    while(str[i]!='\0'){
        if(str[i]==' '){
            i++;
            continue;
        }
        if(str[i]=='-'){
            negative=1;
            i++;
        }
        if(isnum(str[i])){
            temp=0;
            while(isnum(str[i])){
                temp= temp*10 + (str[i]-'0');
                i++;
            }
            if(negative){
                insert(-temp);
                negative=0;
            }
            else
                 insert(temp);   
        }
    }
}


void bubbleSort() {
    if (head == NULL) return;

    node* i;
    node* j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void rotateKth(int k){
    if (head == NULL || head->next == NULL) return;
    
    node *ptr = head;
    node *p = NULL;
    node *kNode = NULL;
    
    while (ptr->next != NULL) {
        if (ptr->next->data == k) {
            p = ptr;    
            kNode = ptr->next; 
            break;
        }
        ptr = ptr->next;
    }

    if (kNode == NULL) {
        printf("Node with value %d not found.\n", k);
        return;
    }

    node *last = kNode;
    while (last->next != NULL) {
        last = last->next;
    }

    p->next = NULL;
    last->next = head; 
    head = kNode;
}

int main(){
    char str[100];
    printf("Enter number string: ");
    scanf("%[^\n]", str);

    parseString(str);
    
    int k;
    printf("Enter k value: ");
    scanf("%d", &k);

    printf("Original list: ");
    display();
    printf("\n");
    
    bubbleSort();
    printf("Sorted list: ");
    display();
    printf("\n");

    rotateKth(k);
    printf("Resultant list: ");
    display();

    return 0;
}
