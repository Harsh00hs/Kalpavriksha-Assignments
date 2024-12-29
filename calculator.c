#include "stdio.h"
#define max_length 100

// for giving string as parameter use (char *exp) or (char exp[]) or (char exp[N])
// normal way is for array (int arr)

int isDigit(char val){
    if (val >= '0' && val <= '9')
        return 1;
    return 0;
}

int isOperator(char val){
    if (val == '+' || val == '-' || val == '*' || val == '/')
        return 1;
    return 0;
}

int isSpace(char val){
    if (val == ' ' || val == '\n' || val == '\t')
        return 1;
    return 0;
}

int operationPerformer(int left, int right, char operation){
    switch (operation){
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right != 0)
            return left / right;
        return -1;
    default:
        return -1;
    }
}

int calculator(char *exp){
    int numbers[max_length];
    int operators[max_length];
    int num_index = -1;
    int op_index = -1;

    int i=0;

    while (exp[i] != '\0'){
        int val = exp[i];
        
        if(isSpace(val)){
            i++;
            continue;
        }

        if(isDigit(val)){
            int num=0;
            while(isDigit(exp[i])){
                num = num*10 + (exp[i] - '0');
                i++;
            }
            i--;
            numbers[++num_index]=num;
        }
        else if(isOperator(val)){
            // for negative number
            if(val == '-' && (i == 0 || isOperator(exp[i-1]) )){
                i++;
                int num=0;
                while(isDigit(exp[i])){
                    num = num*10+(exp[i]-'0');
                    i++;
                }
                i--;
                numbers[++num_index] = -num;
            } else{
                // the precedence is being checked here
                while(op_index != -1 && ((operators[op_index] == '*' || operators[op_index] == '/') || (val == '+' || val == '-'))){
                    int right = numbers[num_index--];
                    int left = numbers[num_index--];
                    char op = operators[op_index--];

                    numbers[++num_index]=operationPerformer(left, right, op);
                }
                operators[++op_index]=val;
            }
        }
        else{
            return -1;
        }
        i++;
    }

    while(op_index != -1){
        int right = numbers[num_index--];
        int left = numbers[num_index--];
        char op = operators[op_index--];
        numbers[++num_index]=operationPerformer(left, right, op);
    }

    return numbers[num_index];
    
}

int main(){
    char exp[100];
    printf("Enter the expression to be calculated: ");
    scanf("%[^\n]", exp); // take input till next line is encountered
    printf("Entered expression is: %s. \n", exp);

    int result = calculator(exp);

    if (result == -1)
        printf("Error: Invalid Expression \n");
    else
        printf("\n The calculated result is: %d. \n", result);

    return 0;
}