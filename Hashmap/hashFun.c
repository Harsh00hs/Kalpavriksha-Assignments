#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define tableSize 5
#define maxLen 100

typedef struct node{
    int id;
    char name[maxLen];
    int age;
    struct node* next;
}node;

typedef struct hashMap{
    node* tables[tableSize];
}hashMap;

void initHash(hashMap* map){
    for(int i=0; i<tableSize; i++)
        map->tables[i]=NULL;
}

int hash(int id){
    return (id*31)%tableSize;
}

void insert(hashMap* map, int id, char name[],int age){
    int index=hash(id);
    node* ptr=(node*)malloc(sizeof(node));
    ptr->id=id;
    strcpy(ptr->name, name);
    ptr->age=age;
    ptr->next=NULL;
    
    if(map->tables[index]==NULL)
        map->tables[index]=ptr;
    else{
        node* temp=map->tables[index];
        while(temp->next)
            temp=temp->next;
        temp->next=ptr;
    }
    printf("Inserted Id-%d on table slot-%d\n", id, index);
}

void display(hashMap* map){
    for(int i=0; i<tableSize; i++){
        printf("Table[Slot-%d]: ", i);
        if(map->tables[i]==NULL)
            printf("------\t------\n");
        else{
            node* curr=map->tables[i];
            while(curr){
                printf("Id-%d, Name-%s, Age-%d -> NULL\n", curr->id, curr->name, curr->age);
                if(curr->next!=NULL)
                    printf("\t\t\t   ");
                curr=curr->next;
            }
        }
    }
}

void search(hashMap* map, int id){
    int index=hash(id);
    if(map->tables[index]==NULL){
        printf("Id-%d Not found in any slot.\n", id);
        return;
    }
    node* curr=map->tables[index];
    while(curr){
        if(curr->id==id){
            printf("Found on Slot-%d: Id-%d, Name-%s, Age-%d\n", index, curr->id, curr->name, curr->age);
            return;
        }
        curr=curr->next;
    }
    printf("Id-%d Not found in any slot.\n", id);
    
    //if pass all value in hash function and trying to search only by id but the time comp will be o(n^2-3);
    // int found=0;
    // for(int i=0; i<tableSize; i++){
    //     node* curr=map->tables[i];
    //     while(curr){
    //         if(curr->id==id){
    //             printf("Found on Slot-%d: Id-%d, Name-%s, Age-%d\n", i, curr->id, curr->name, curr->age);
    //             found=1;
    //             break;
    //         }
    //         curr=curr->next;
    //     }
    //     if(found) break;
    // }
    // if(!found)
    //     printf("Id-%d Not found in any slot.\n", i);
}

void delete(hashMap* map, int id){
    int index=hash(id);
    if(map->tables[index]==NULL){
        printf("Id-%d Not found in any slot.\n", id);
        return;
    }
    node* curr=map->tables[index];
    
    if (curr->id == id) {
        map->tables[index] = curr->next; // Remove the first node
        printf("The data %d, %s, %d removed.\n", curr->id, curr->name, curr->age);
        free(curr);
        return;
    }
    
    while(curr->next){
        if(curr->next->id==id){
            node *temp=curr->next;
            curr->next=temp->next;
            printf("Th data %d, %s, %d removed.",temp->id, temp->name, temp->age);
            free(temp);
            return;
        }
        curr=curr->next;
    }
    printf("Id-%d Not found in any slot.\n", id);
    // printf("Id-%d Not found in any slot.\n", id);
}

int main(){
    hashMap map;
    initHash(&map);
    
    int id, age;
    char name[maxLen];
    int ch;
    int searchId;
    int deleteId;
    printf("Hashmap menu\n");
    while(1){
        printf("-------------\n");
        printf("\t1.Insert\n");
        printf("\t2.Display\n");
        printf("\t3.Search\n");
        printf("\t4.Delete\n");
        printf("Enter operation: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                printf("Enter id: "); scanf("%d", &id); getchar();
                if(id==-1) break;
                printf("Enter name: "); scanf("%[^\n]", name);
                printf("Enter age: "); scanf("%d", &age);
                insert(&map, id, name, age);
                break;
            case 2:
                display(&map);
                break;
            case 3:
                printf("Enter search id: ");
                scanf("%d", &searchId);
                search(&map, searchId);
                break;
            case 4:
                printf("Enter delete id: ");
                scanf("%d", &deleteId);
                delete(&map, deleteId);
                break;
            case 5:
                printf("Exiting:\n");
                return 0;
            default:
                printf("Invalid\n");
                break;
        }
        
        // printf("%d\n", hash(id,name,age));
    }
    display(&map);
    
    return 0;
}