#include <stdio.h>
#include <stdlib.h>
#define max 3

int arr[max],top=-1;

void push(){
    if(top==(max-1)){
        printf("Stack overflow!\n");
        return;
    }
    printf("Enter the value:");
    int n;
    scanf("%d",&n);
    arr[++top]=n;
    return;
}

void pop(){
    if(top==-1){
        printf("Stack underflow!\n");
        return;
    }
    printf("Item deleted: %d\n",arr[top--]);
}

void display(){
    if(top==-1){
        printf("Stack underflow!\n");
        return;
    }
    printf("\nStack:\n\n");
    for(int i = top; i >= 0; i--){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}

int main(){
    printf("\n----MENU----\n1.Push\n2.Pop\n3.Display\n");
    int ch;
    for(;;){
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
}