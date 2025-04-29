// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum status{
    best=1,
    high,
    middle,
    low,
    least
}status;

typedef struct node{
    int id;
    status grade;
    char name[100];
    struct node* next;
}node;

node* head=NULL;

status to_enum(char grade[]){
    if(strcmp(grade, "best")==0) return best;
    if(strcmp(grade, "high")==0) return high;
    if(strcmp(grade, "middle")==0) return middle;
    if(strcmp(grade, "low")==0) return low;
    if(strcmp(grade, "least")==0) return least;
    return least;
}

char* to_string(status grade){
    if(grade==best) return "best";
    if(grade==high) return "high";
    if(grade==middle) return "middle";
    if(grade==low) return "low";
    if(grade==least) return "least";
    return "least";
}

void insert(int id, char name[], status grade){
    node* ptr=(node*)malloc(sizeof(node));
    ptr->id=id;
    strcpy(ptr->name, name);
    ptr->grade=grade;
    ptr->next=NULL;
    
    if(head==NULL){
        head=ptr;
        return;
    }
    
    node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=ptr;
}
void sort(){
    node* ptr=head;
    if(head==NULL || head->next==NULL)
        return;
    
    for(node* i=head; i!=NULL; i=i->next){
        for(node* j=i->next; j!=NULL; j=j->next){
            if(strcmp(i->name, j->name)>0){
                int tempid= i->id;
                i->id=j->id;
                j->id=tempid;
                
                char name[100];
                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);
                
                status tempgrade=i->grade;
                i->grade=j->grade;
                j->grade=tempgrade;
            }
            if(i->grade > j->grade){
                int tempid= i->id;
                i->id=j->id;
                j->id=tempid;
                
                char name[100];
                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);
                
                status tempgrade=i->grade;
                i->grade=j->grade;
                j->grade=tempgrade;
            }
        }
    }
}

void display(){
    sort();
    node* curr=head;
    while(curr){
        printf("%d, %s, %s\n", curr->id, curr->name, to_string(curr->grade));
        curr=curr->next;
    }
    printf("\n");
}

void delete(int id){
    if(head==NULL)
        return;
    
    node* ptr=head;
    if(ptr->id==id){
        head=ptr->next;
        free(ptr);
        return;
    }
    while(ptr->next){
        if(ptr->next->id==id){
            node* p=ptr;
            ptr=ptr->next;
            p->next=ptr->next;
            free(ptr);
            return;
        }
        ptr=ptr->next;
    }
    if(ptr->next==NULL){
        printf("Id-%d not found", id);
    }
}

void update(int id, status grade){
    if(head==NULL) return;
    
    node* ptr=head;
    while(ptr){
        if(ptr->id==id){
            ptr->grade=grade;
            break;
        }
        ptr=ptr->next;
    }
    // printf("----------->%d",ptr->id);
    if(ptr==NULL){
        printf("The id not found %d\n", id);
        return;
    }
}

int main() {
    int m;
    scanf("%d", &m);
    
    int ch;
    printf("1. Add\n");
    printf("2. display\n");
    printf("3. delete\n");
    printf("4. update\n");
    int id;
    char name[100];
    char grade[10];
    int deleteid;
    int updateid;
    char updategrade[10];
    
    while(m){
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter id: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter grade: ");
                getchar();
                scanf("%s", grade);
                insert(id, name, to_enum(grade));
                break;
            case 2:
                printf("The grades are: \n");
                display();
                break;
            case 3:
                printf("enter id to delete: ");
                scanf("%d", &deleteid);
                delete(deleteid);
                break;
            case 4:
                printf("Enter the id to update: ");
                scanf("%d", &updateid);
                printf("enter grade: ");
                scanf("%s", updategrade);
                update(updateid, to_enum(updategrade));
                break;
            
            default:
            printf("Invalid\n");
                break;
        }
        m--;
    }

    return 0;
}