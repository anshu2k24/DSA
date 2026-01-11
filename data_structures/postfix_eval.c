#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s[30],top=-1;

void push(int ch){
    if(top<30){
        s[++top] = ch;
    }else{
        printf("\nStack overflow\n");
    }
}

int pop(){
    if(top!=-1){
        return s[top--];
    }else{
        printf("\nStack underflow\n");
    }
}

int isdig(char ch){
    if(((ch-'0') > 0) && ((ch-0) < '9')){
        return 1;
    }
    return 0;
}

int op(int a, int b, char ch){
    int res;
    if(ch == '+'){
        res = a+b;
    }else if(ch == '-'){
        res = a-b;
    }else if(ch == '*'){
        res = a*b;
    }else if(ch == '/'){
        res = a/b;
    }
    return res;
}

int main(){
    char postfix[30],ch;
    int a,b,res;

    printf("Enter postfix:");
    scanf("%s",postfix);

    for(int i = 0; i < strlen(postfix); i++){
        ch = postfix[i];
        if(isdig(ch)){
            push(ch-'0');
        }else{
            b = pop();
            a = pop();
            res = op(a,b,ch);
            push(res);
        }
    }

    printf("\nThe output is: %d",pop());

    return 0;
}