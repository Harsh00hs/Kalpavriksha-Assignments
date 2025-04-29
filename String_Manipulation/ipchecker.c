#include "stdio.h"
#define maxLength 1000

int stringLength(char *str){
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int ipchecker(char *str){
    int num[4];
    int len= stringLength(str);
    int dotCount=0;
    int numindex=0;
    
    for(int i=0; i<len;){
        if(str[i] == '.'){
            dotCount++;
            i++;
        }
        if(str[i] == '.'){
            printf("Invalid IP address\n");
        }
        int temp=0;
        while(str[i] >= '0' && str[i] <= '9'){
            temp = temp*10 + (str[i] - '0');
            i++;
            if(temp==0 && (str[i] >= '0' && str[i] <= '9')){
                printf("Invalid Ip Address.\n");
                return 0;
            }
        }

        num[numindex++]= temp;
    }
    int numcount=0;

    for(int i=0; i<numindex; i++){
        if(num[i] > 255 || num[i] < 0)
            numcount++;
    }
    if(dotCount == 3 && numcount == 4){
        printf("Valid ip address");
    }else{
        printf("Invalid ip");
    }

}

int main(){
    char str[maxLength];
    printf("Enter a string: ");
    // fgets(str, maxLength, stdin);
    // gets(str);
    scanf("%s", str);
    printf("Enter Ipv4 Address: %s\n", str);

    ipchecker(str);
    return 0;
}