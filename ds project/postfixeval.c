#include <stdio.h>
#include <string.h>
#include <math.h>
#define ms 40

int stack[ms];
int top = -1;

void push(int n){
    if(top == (ms-1)){
        printf("stack overflow!");
        return;
    }else{
        stack[++top]=n;
    }
}

int pop(){
    if(top != -1){
        return stack[top--];
    }else{
        printf("stack underflow!");
        return 0;
    }
}

int op(int a, int b, char symb){
    int res=0;
    switch (symb){
        case '+':
            res= a+b;
            break;
        case '-':
            res= a-b;
            break;
        case '*':
            res= a*b;
            break;
        case '/':
            res= a/b;
            break;
    }
    return res;
}

int isdig(char symb){
    return ((symb>='0') && (symb<='9'));
}

int main(){
    char postfix[40];
    int a,b;
    char symbol;
    printf("Enter postfix:");
    scanf("%s",postfix);

    for(int i = 0; i < strlen(postfix); i++){
        symbol = postfix[i];
        if(isdig(symbol)){
            push(symbol-'0');
        }else{
            a = pop();
            b = pop();
            push(op(b,a,symbol));
        }
    }
    printf("Final value: %d",pop());
    return 0;
}