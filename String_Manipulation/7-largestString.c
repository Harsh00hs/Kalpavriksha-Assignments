// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%[^\n]", str);
    
    char largest[100]= " ";
    char current[100];
    
    int i=0, j=0;
    while(str[i]!='\0'){
        if(str[i] != ' ' && str[i] != '\0'){
            current[j++]=str[i];
        }else{
            current[j]=='\0';
            
            if (strlen(current) > strlen(largest)) {
                strcpy(largest, current);
            }
            j=0;
        }
        i++;
    }
    printf("%s", largest);
    
    return 0;
}