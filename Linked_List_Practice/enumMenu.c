#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum status{
    pending=1,
    shipped,
    delivered,
    cancelled
}status;

typedef struct node{
    int id;
    char customer[100];
    status type;
    struct node* next;
}node;

node* head=NULL;

status to_enum(char* type){
    if(strcmp(type, "shipped")==0) return shipped;
    if(strcmp(type, "pending")==0) return pending;
    if(strcmp(type, "cancelled")==0) return cancelled;
    if(strcmp(type, "delivered")==0) return delivered;
    return cancelled;
}

char *to_string(status type){
    switch(type){
        case shipped: return "Shipped";
        case delivered: return "Delivered";
        case pending: return "Pending";
        case cancelled: return "Cancelled";
        default: return "Cancelled";
    }
}

void insert(int id, char name[], status type){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->id=id;
    strcpy(ptr->customer, name);
    ptr->type=type;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
        return;
    }

    node* temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=ptr;
}

void sorting(){
    for(node* i=head; i!=NULL; i=i->next){
        for(node* j=i->next; j!=NULL; j=j->next){
            if(i->type > j->type){
                int tempId=i->id;
                i->id=j->id;
                j->id=tempId;
                
                char name[20];
                strcpy(name, i->customer);
                strcpy(i->customer, j->customer);
                strcpy(j->customer, name);
                
                status temp=i->type;
                i->type=j->type;
                j->type=temp;
            }
        }
    }
}

void display(){
    if(head==NULL){
        printf("0\n");
        return;
    }
    
    sorting();

    node* curr=head;
    while(curr){
        printf("%d, %s, %s\n", curr->id, curr->customer, to_string(curr->type));
        curr=curr->next;
    }
    printf("\n");
}

void update(int id, status type){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    node* temp=head;
    while(temp){
        if(temp->id==id){
            temp->type=type;
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Id-%d not found.\n", id);
        return;
    }
    printf("Order ID-%d status changed to %s\n", id, to_string(type));
}

void delete(int id){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    node* temp=head;
    if(temp->id==id){
        head=temp->next;
        free(temp);
        return;
    }

    while(temp->next!=NULL){
        if(temp->next->id==id){
            node* p=temp->next;
            temp->next=p->next;
            free(p);
            return;
        }
        temp=temp->next;
    }
    printf("Node with ID %d not found.\n", id);
}

int main(){
    int m;
    printf("No of operations: ");
    scanf("%d", &m);

    int id;
    char name[100];
    char type[20];
    int ch;
    printf("1.add\n");
    printf("2.update\n");
    printf("3.delete\n");
    printf("4.display\n");
    while(m>0){
        int updateid;
        char updateStatus[20];
        int deleteId;
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter id, name, customer\n");
                scanf("%d", &id);
                scanf("%s", name);
                getchar();
                scanf("%s", type);
                insert(id, name, to_enum(type));
                break;
            case 2:
                printf("Enter the id to update the order: ");
                scanf("%d", &updateid);
                printf("Enter the status to update: ");
                scanf("%s", updateStatus);
                update(updateid, to_enum(updateStatus));
                break;
            case 3:
                printf("Enter the id to delete: ");
                scanf("%d", &deleteId);
                delete(deleteId);
                break;
            case 4:
                printf("The orders are: \n");
                display();
                break;
            default:
                printf("Inavlid\n");
                break;
            
        }
        m--;
    }

    return 0;
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