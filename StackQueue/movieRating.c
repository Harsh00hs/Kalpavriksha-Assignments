#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxLen 1000

typedef struct node{
    char movie[maxLen];
    int rating;
    struct node* next;
}node;

node* head=NULL;

void rate(char movie[], int rating){
    node* ptr=(node*)malloc(sizeof(node));
    strcpy(ptr->movie, movie);
    ptr->rating=rating;
    ptr->next=head;
    head=ptr;
}

void delete(char movie[]){
    if(head==NULL){
        printf("NULL\n");
        return;
    }
    node* curr=head;
    node* prev=NULL;
    while(curr){
        if(strcmp(movie, curr->movie)==0){
            if(prev==NULL)
                head=curr->next;
            else
                prev->next=curr->next;
            free(curr);
            printf("Movie '%s' deleted.\n", movie);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    
    if(curr==NULL)
        printf("not found\n");
}

void top(){
    if(head==NULL){
        printf("no movie rated\n");
        return;
    }
    node* curr=head;
    int rate=0;
    while(curr){
        if(curr->rating>rate)
            rate=curr->rating;
        curr=curr->next;
    }
    printf("%d\n", rate);
    curr=head;
    
    while(curr){
        if(curr->rating==rate)
            printf("Movie- %s with rating- %d\n", curr->movie, curr->rating);
        curr=curr->next;
    }
    
}


int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    char str[maxLen];
    
    char movie[maxLen];
    int rating;
    
    while(n--){
        scanf("%[^\n]", str);
        getchar();
        
        char *token=strtok(str, " ");
        
        if(strcmp(token, "RATE")==0){
            token=strtok(NULL, " ");
            strcpy(movie, token);
            token=strtok(NULL, " ");
            rating=atoi(token);
            if(rating>10 || rating<0)
                printf("Invalid\n");
            else
                rate(movie, rating);
        }
        else if(strcmp(token, "REMOVE")==0){
            token=strtok(NULL, " ");
            strcpy(movie, token);
            
            delete(movie);
        }
        else if(strcmp(token, "TOP")==0){
            top();
        }
        else{
            printf("invalid\n");
        }
    }

    return 0;
}