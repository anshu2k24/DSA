#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int info;
    struct NODE * link;
};

typedef struct NODE * node;

node insert_front(node first){
    int val;
    printf("Enter the value to be inserted:");
    scanf("%d",&val);
    node temp = (node) malloc(sizeof(struct NODE));
    temp->info = val;
    temp->link = first;
    printf("Inserted!");
    return temp;
}

node insert_rear(node first){
    int val;
    printf("Enter the value to be inserted:");
    scanf("%d",&val);
    node temp = (node) malloc(sizeof(struct NODE));
    temp->info = val;
    temp->link = NULL;
    if(first == NULL){
        printf("Inserted!");
        return temp;
    }
    node cur = first;
    while(cur->link!=NULL){
        cur = cur->link;
    }
    cur->link = temp;
    printf("Inserted!");
    return first;
}

node delete_front(node first){
    if(first==NULL){
        printf("Empty SLL");
        return NULL;
    }
    node cur = first;
    first = first->link;
    free(cur);
    printf("Deleted!");
    return first;
}

node delete_rear(node first){
    if(first==NULL){
        printf("Empty SLL");
        return NULL;
    }
    node prev,cur = first;
    while(cur->link!=NULL){
        prev = cur;
        cur= cur->link;
    }
    prev->link = NULL;
    free(cur);
    printf("Deleted!");
    return first;
}

void display(node first){
    if(first==NULL){
        printf("Empty SLL");
        return;
    }
    node cur = first;
    printf("\n-----SLL-------\n");
    while(cur!=NULL){
        printf("%d\t",cur->info);
        cur= cur->link;
    }
}


int main(){
    node first = NULL;
    int ch,val;
    printf("\n-----MENU----\n");
    printf("1.Insert_front\n2.Insert_rear\n3.Delete_front\n4.Delete_rear\n5.Display\n");
    for(;;){
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                first = insert_front(first);
                break;
            case 2:
                first = insert_rear(first);
                break;
            case 3:
                first = delete_front(first);
                break;
            case 4:
                first = delete_rear(first);
                break;
            case 5:
                display(first);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}