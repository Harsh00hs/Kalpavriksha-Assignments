#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef enum Severity{
    critical=1,
    serious,
    stable
}Severity;

typedef struct node{
    int id;
    Severity type;
    struct node* next;
}node;

node* head=NULL;

Severity to_enum(char* status){
    if(strcmp(status, "critical")==0) return critical;
    if(strcmp(status, "serious")==0) return serious;
    if(strcmp(status, "stable")==0) return stable;
    return stable;
}

char* to_string(Severity status){
    switch(status){
        case critical: return "critical";
        case serious: return "serious";
        case stable: return "stable";
        default: return "stable";
    }
}

void insert(int id, Severity status){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->id=id;
    ptr->type=status;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=ptr;
}

void sorting(){
    if(head==NULL || head->next==NULL)
        return;
    
    for(node* i=head; i!=NULL; i=i->next){
        for(node* j=i->next; j!=NULL; j=j->next){
            if(i->type>j->type){
                int tempId=i->id;
                i->id=j->id;
                j->id=tempId;

                Severity temp=i->type;
                i->type=j->type;
                j->type=temp;
            }
        }
    }
}

void display(){
    node* curr=head;
    while(curr){
        printf("%d %s\n", curr->id, to_string(curr->type));
        curr=curr->next;
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    int id;
    char severity[20];
    for(int i=0;i<n;i++){
        scanf("%d %s",&id,severity);
        insert(id, to_enum(severity));
    }
    sorting();
    display();
}