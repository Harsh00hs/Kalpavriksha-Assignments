// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int palindrone(char *str){
    int n=strlen(str);
    char rev[n+1];
    int curr=0;
    for(int i=n-1; i>=0; i--){
        rev[curr++]=str[i];
    }
    rev[curr]='\0';
    
    return strcmp(str, rev)==0;
}

int main() {
    char str[100];
    scanf("%[^\n]", str);
    
    char largest[100]= " ";
    char current[100];
    
    int i=0, j=0;
    while(str[i]!='\0'){
        if(str[i] != ' ' && str[i] != '\0'){
            current[j++]=str[i];
        }else if(palindrone(current)){
            current[j]='\0';
            
            if (palindrone(current) && strlen(current) > strlen(largest)) {
                strcpy(largest, current);
            }
            j=0;
        }
        i++;
    }
    printf("%s", largest);
    
    return 0;
}