#include <stdio.h>

#include "string.h"

int main(){
    char str[100];
    printf("Enter the string: ");
    scanf("%s", &str);
    // printf("%s \n", &str);

    int len = strlen(str);
    // printf("%d\n", len);

    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if (str[i] > str[j]){
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    int count=1;
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(str[i] == str[j]){
                count++;
                i++;
            }else{
                break;
            }
        }
        printf("%c%d", str[i], count);
        count=1;
    }

    
    return 0;
}