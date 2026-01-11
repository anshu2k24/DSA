#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char s[30];
int top = -1;

void push(char ch){
    if(top<29){
        s[++top] = ch;
    }
}

char pop(){
    return s[top--];
}

int prior(char ch){
    int p;
    if(ch == '#' || ch == '('){
        p = 1;
    }else if(ch == '+' || ch == '-'){
        p = 2;
    }else if(ch == '*' || ch == '/'){
        p = 3;
    }else if(ch == '^' || ch == '$'){
        p = 4;
    }
    return p;
}

int main(){
    char infix[30],postfix[30];
    s[++top]='#';

    int j = 0;
    printf("Enter the infix expression:");
    scanf("%s",infix);

    for(int i = 0; i< strlen(infix);i++){
        char ch = infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }else if(ch == '('){
            push(ch);
        }else if(ch == ')'){
            while(s[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }else{
            while(prior(ch)<=prior(s[top])){
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(s[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("\nThe postfix expression is:%s\n",postfix);
}