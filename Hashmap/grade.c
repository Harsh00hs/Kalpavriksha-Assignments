#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define tableSize 10
#define maxLen 100

typedef struct node{
    int id;
    char name[maxLen];
    char grade;
    int marks;
    struct node* next;
}node;

typedef struct hashMap{
    node* table[tableSize];
}hashMap;

void initHash(hashMap* map){
    for(int i=0; i<tableSize; i++)
        map->table[i]=NULL;
}

int hash(int id){
    return id%tableSize;
}

node* createNode(int id, char name[], char grade, int marks){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    strcpy(newnode->name, name);
    newnode->grade=grade;
    newnode->marks=marks;
    newnode->next=NULL;
    return newnode;
}

void insert(hashMap* map, int id, char name[], char grade, int marks){
    int index=hash(id);
    node *newNode=createNode(id, name, grade, marks);
    
    if(map->table[index]==NULL){
        map->table[index]=newNode;
    }else{
        node* curr=map->table[index];
        while(curr->next)
            curr=curr->next;
        
        curr->next=newNode;
    }
}

void display(hashMap* map){
    for(int i=0; i<tableSize; i++){
        if(map->table[i]==NULL){}
            // continue;
        else{
            node* curr=map->table[i];
            while(curr){
                printf("Table Slot-%d: Id-%d Name-%10s  Grade-%c  Marks-%02d  \n", i, curr->id, curr->name, curr->grade, curr->marks);
                curr=curr->next;
            }
        }
    }
}

void marksRange(hashMap* map, int min_marks, int max_marks){
    printf("\nThe student within %d - %d marks range are: \n", min_marks, max_marks);
    for(int i=0; i<tableSize; i++){
        node* curr=map->table[i];
        while(curr){
            if(curr->marks >= min_marks && curr->marks <= max_marks)
                printf("Table Slot-%d: Id-%d Name-%10s  Grade-%c  Marks-%02d  \n", i, curr->id, curr->name, curr->grade, curr->marks);
            curr=curr->next;
        }
    }
}

void specificGrade(hashMap* map, char grade){
    int count=0;
    printf("\nThe students with %c grade are: \n", grade);
    for(int i=0; i<tableSize; i++){
        node* curr=map->table[i];
        while(curr){
            if(curr->grade==grade){
                printf("Table Slot-%d: Id-%d Name-%10s  Grade-%c  Marks-%02d  \n", i, curr->id, curr->name, curr->grade, curr->marks);
                count++;
            }
            curr=curr->next;
        }
    }
    printf("So, the number of student with %c grade are %d.\n", grade, count);
}

void highLow(hashMap* map){
    int min=101, max=0;
    for(int i=0; i<tableSize; i++){
        node* curr=map->table[i];
        while(curr){
            if(curr->marks>max)
                max=curr->marks;
            if(curr->marks<min)
                min=curr->marks;
            curr=curr->next;
        }
    }
    printf("\nMin marks: %d\n", min);
    printf("Max marks: %d\n", max);
}

void avgMarks(hashMap* map){
    float avg=0;
    int count=0;
    for(int i=0; i<tableSize; i++){
        node* curr=map->table[i];
        while(curr){
            avg+=curr->marks;
            count++;
            curr=curr->next;
        }
    }
    printf("\nAvg marks of %d students are: %.3f\n", count, avg/count);
}

void update(hashMap* map, int id, char grade, int marks){
    int index=hash(id);
    node* curr=map->table[index];
    if(curr==NULL){
        printf("\nId not found\n");
        return;
    }
    while(curr){
        if(curr->id==id){
            curr->grade=grade;
            curr->marks=marks;
            printf("\nUpdated Slot-%d: Id-%d Name-%10s  Grade-%c  Marks-%02d\n", index, curr->id, curr->name, curr->grade, curr->marks);
            return;
        }
        curr=curr->next;
    }
    if(curr==NULL)
        printf("\nId not found\n");
}

void delete(hashMap* map, int id){
    int index=hash(id);
    node* curr=map->table[index];
    node* prev=NULL;
    
    if(curr==NULL){
        printf("\nId not found\n");
        return;
    }
    
    while(curr){
        if(curr->id==id){
            if(prev==NULL)
                map->table[index]=curr->next;
            else
                prev->next=curr->next;
            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    
    if(curr==NULL)
        printf("\nId not found\n");
}

int main(){
    hashMap map;
    initHash(&map);
    
    insert(&map, 101, "joana", 'A', 85);
    insert(&map, 102, "jimmy", 'B', 70);
    insert(&map, 103, "alex", 'A', 83);
    insert(&map, 104, "eve", 'C', 56);
    insert(&map, 105, "denny", 'E', 35);
    insert(&map, 106, "yui", 'D', 45);
    insert(&map, 107, "elizabeth", 'B', 74);
    insert(&map, 108, "jack", 'D', 23);
    insert(&map, 111, "lucifer", 'A', 98);
    
    display(&map);

    marksRange(&map, 30, 70);
    
    specificGrade(&map, 'E');
    
    highLow(&map);
    
    avgMarks(&map);
    
    update(&map, 104, 'B', 77);
    
    delete(&map, 105);
    
    display(&map);
    
    return 0;
}