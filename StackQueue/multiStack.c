#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}stack;

int isFull(stack* s){
    return s->top==s->size-1;
}

int isEmpty(stack* s){
    return s->top==-1;
}

void display(stack* s){
    printf("The elements of stack are: ");
    for(int i=0; i<=s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
}

void push(stack* s, int val){
    if(isFull(s))
        printf("Overflowed! Stack is full.\n");
    else{
        s->arr[++s->top]=val;
        printf("Pushed: %d\n", val);
    }
}

void pop(stack* s){
    if(isEmpty(s))
        printf("Underflow! Stack is empty.\n");
    else{
        printf("Popped value: %d\n", s->arr[s->top--]);
    }
}

int main(){
    int n, m;
    printf("Enter size of stack 1: ");
    scanf("%d", &n);
    printf("Enter size of stack 2: ");
    scanf("%d", &m);
    int val;

    stack* s1=(stack*)malloc(sizeof(stack));
    s1->size=n;
    s1->top=-1;
    s1->arr=(int*)malloc(s1->size*sizeof(int));

    stack* s2=(stack*)malloc(sizeof(stack));
    s2->size=m;
    s2->top=-1;
    s2->arr=(int*)malloc(s2->size*sizeof(int)); 
    
    for(int i=0; i<n; i++){
        scanf("%d", &val);
        push(s1, val);
    }

    for(int i=0; i<m; i++){
        scanf("%d", &val);
        push(s2, val);
    }

    display(s1);
    display(s2);
    
    return 0;
}