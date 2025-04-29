#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#define tableSize 10
#define maxLen 256

typedef struct person{
    char name[maxLen];
    int age;
    // struct person* next;
}person;

// typedef struct hashMap{
//     person* entries[tableSize];
// }hashMap;

person* hashTable[tableSize];

unsigned int hash(char name[]){
    int len=strlen(name);
    int hashValue=0;
    for(int i=0; i<len; i++){
        hashValue+=name[i];
    }
    return hashValue % tableSize;
}

void initHash(){
    for(int i=0; i<tableSize; i++)
        hashTable[i]=NULL;
}

void printTable(){
    for(int i=0; i<tableSize; i++){
        if(hashTable[i]==NULL){
            printf("\t%i\t---\n", i);
        }else{
            printf("\t%i\t%s\n", i, hashTable[i]->name);
        }
    }
}

bool hashInsert(person* p){
    if(p==NULL)
        return false;
    int index=hash(p->name);

    for(int i=0; i<tableSize; i++){
        int try=(i+index)%tableSize;
        if(hashTable[try]==NULL)
            hashTable[try]=p;
            return true;
    }
    
    // if(hashTable[index]!=NULL)
    //     return false;
    
    // hashTable[index] =p;
    return true;
}

person* hashSearch(char *name){
    int index=hash(name);
    if(hashTable[index]!=NULL && strcmp(hashTable[index]->name, name)==0)
        return hashTable[index];
    else
        return NULL;
}

person* hashDelete(char *name){
    int index=hash(name);
    if(hashTable[index]!=NULL && strcmp(hashTable[index]->name, name)==0){
        person* temp=hashTable[index];
        hashTable[index]=NULL;
        return temp;
    }else
        return NULL;
}

int main(){
    initHash();
    // printTable();

    person jacob= {.name="Jacob", .age=25};
    person meryy= {.name="meryy", .age=24};
    person jaona= {.name="jaona", .age=21};
    person james= {.name="james", .age=22};
    person june= {.name="june", .age=26};
    person may= {.name="may", .age=22};
    person jimmy= {.name="jimmy", .age=28};
    person billy= {.name="billy", .age=2};
    person jemmy= {.name="jemmy", .age=32};
    person lana= {.name="lana", .age=20};
    person jone= {.name="jone", .age=92};

    hashInsert(&jacob);
    hashInsert(&meryy);
    hashInsert(&jaona);
    hashInsert(&james);
    hashInsert(&june);
    hashInsert(&may);
    hashInsert(&jimmy);
    hashInsert(&billy);
    hashInsert(&jemmy);
    hashInsert(&lana);
    hashInsert(&jone);

    printTable();

    person* temp=hashSearch("james");
    if(temp==NULL){
        printf("Not Found\n");
    }else
        printf("Found %s.\n", temp->name);
    
    temp=hashSearch("george");
    if(temp==NULL){
        printf("Not Found\n");
    }else
        printf("Found %s.\n", temp->name);

    person* del=hashDelete("james");
    if(del==NULL){
        printf("Not Found\n");
    }else
        printf("Found %s.\n", del->name);

    printTable();
    
    // printf("Harsh => %u\n", hash("harsh"));
    // printf("jacob => %u\n", hash("jacob"));
    // printf("puneet => %u\n", hash("puneet"));
    // printf("jaona => %u\n", hash("jaona"));
    // printf("niona => %u\n", hash("niona"));
    // printf("rey => %u\n", hash("rey"));
}