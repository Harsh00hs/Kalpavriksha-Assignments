// Online C compiler to run C program online
#include <stdio.h>

int isnum(char c){
    return(c>='0' && c<='9');
}

int getrowlen(char *str){
    int row=0, i=0;
    while(str[i]!='\0'){
        if(str[i]==']'){
            row++;
        }
        i++;
    }
    return row-1;
}

int getcollen(char *str, int rowlen){
    int count=0, i=0;
    while(str[i]!='\0'){
        if(isnum(str[i])){
            count++;
            while(isnum(str[i]))
                i++;
        }
        i++;
    }
    return count/rowlen;
}

int main() {
    char str[100];
    printf("Entere here: ");
    scanf("%[^\n]", str);
    
    int row = getrowlen(str);
    int col = getcollen(str, row);
    
    printf("%d %d\n", row, col);
    
    int matrix[row][col];
    
    int r_index=0, c_index=0;
    int negative=0;
    int temp=0;
    int i=0;
    
    while(str[i]!='\0'){
        if(str[i]=='-')
            negative=1;
        if(isnum(str[i])){
            temp= temp*10 + (str[i]-'0');
        }else if(str[i]==' ' || str[i]==',' || str[i]==']'){
            if(negative){
                matrix[r_index][c_index++]=-temp;
                negative=0;
            }
            else
                matrix[r_index][c_index++]=temp;
            temp=0;
        }else if(str[i] == '['){
            if(c_index>0){
                c_index=0;
                r_index++;
            }
        }
        i++;
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}