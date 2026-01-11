#include <stdio.h>
#include <stdlib.h>
#define max 10

int insert(int val,int n,int arr[]){
    if(n==max){
        printf("Heap is full!");
        return n;
    }
    int c,p;
    c = n;
    p = (c-1)/2;
    while((c!=0) && (arr[p]<val)){
        arr[c]=arr[p];
        c=p;
        p=(c-1)/2;
    }
    arr[c]=val;
    return ++n;
}

void display(int n,int arr[]){
    if(n==0){
        printf("Empty!");
        return;
    }
    printf("Max Heap:\n");
    for(int i = 0; i< n; i++){
        printf("%d\t",arr[i]);
    }
}

int main(){
    int ch,val,n=0,arr[max];
    printf("\n-----MENU-----\n");
    printf("1.Insert\n2.Display\n");
    for(;;){
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value to be inserted:");
                scanf("%d",&val);
                n = insert(val,n,arr);
                printf("Inserted!");
                break;
            case 2:
                display(n,arr);
                break;
            default:
                exit(0);
        }
    }
}