#include <stdio.h>
#include <stdlib.h>
#define max 5

int q[max];
int f = -1,r = -1;

void insert(){
    if(r == (max-1)){
        printf("Queue overflow!");
        return;
    }
    int n;
    printf("Enter the val:");
    scanf("%d",&n);
    if(f==-1){
        f=0;
    }
    q[++r]=n;
    printf("Inserted\n");
    return;
}

void delete(){
    if(f==-1 || (f > r)){
        printf("Queue underflow!");
        f=r=-1;
        return;
    }
    f++;
    printf("Deleted\n");
    return;
}

void display(){
    if(f==-1 || (f>r)){
        printf("Queue underflow!");
        f=r=-1;
        return;
    }
    printf("\nQueue:\n");
    for(int i = f; i <= r; i++){
        printf("%d\t",q[i]);
    }
}

int main(){
    int ch;
    printf("-----MENU-----\n1.Insert\n2.Delete\n3.Display\n");
    for(;;){
        printf("\n\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
