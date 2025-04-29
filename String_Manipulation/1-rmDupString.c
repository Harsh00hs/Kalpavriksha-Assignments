#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);
    
    char dup[100]=" ";
    int index=0;
    
    for(int i=0; i<strlen(str); i++){
        int isdup=0;
        for(int j=0; j<index; j++){
            if(str[i]==dup[j]){
                isdup=1;
                break;
            }
        }
        if(!isdup){
            dup[index]=str[i];
            dup[index++];
        }
    }
    dup[index]='\0';
    
    printf("%s", dup);

    return 0;
}