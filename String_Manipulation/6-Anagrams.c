// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

void sort(char *str){
    for(int i=0; i< strlen(str); i++){
        for(int j=i+1; j<strlen(str); j++){
            if(str[i]>str[j]){
                int temp=str[i];
                str[i]= str[j];
                str[j]=temp;
            }
        }
    }
}

int isAnagram(char *str1, char *str2){
    int match=1;
    sort(str1);
    sort(str2);
    for(int i=0; i<strlen(str1); i++){
        if(str1[i]!=str2[i]){
            match=0;
        }
    }
    return match;
}

int main() {
    char str[100];
    scanf("%s", str);
    char sec[100];
    scanf("%s", sec);
    
    if(strlen(str) != strlen(sec)){
        printf("Not anagrams");
        return 0;
    }
    
    if(isAnagram(str, sec)){
        printf("Anagrams");
    }else{
        printf("Not Anagrams");
    }
    
    
    
    return 0;
}