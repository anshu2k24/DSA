#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[40];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int prior(char op){
    int p;
    if(op == '(' || op == '#'){
        p=1;
    }else if(op == '+' || op == '-'){
        p=2;
    }else if(op == '*' || op == '/'){
        p=3;
    }else if(op == '$' || op == '^'){
        p=4;
    }
    return p;
}

int main(){
    char postfix[40],infix[40];
    int j = 0;
    push('#');

    printf("Enter infix:");
    scanf("%s",infix);

    for(int i = 0; i < strlen(infix); i++){
        if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }else if(infix[i]=='('){
            push(infix[i]);
        }else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }else{
            while(prior(stack[top])>=prior(infix[i])){
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
    }

    while(stack[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix expression is: %s",postfix);
    return 0;
}