#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int info;
    struct NODE *left;
    struct NODE *right;
};

typedef struct NODE *node;

node insert_front(node first,int val){
    node temp = (node) malloc (sizeof(struct NODE));
    temp->info = val;
    temp->left=temp->right = NULL;
    if(first == NULL){
        return temp;
    }
    first->left = temp;
    temp->right = first;
    return temp;
}

node insert_key(node first,int val,int key){
    node cur,prev;
    node temp = (node) malloc (sizeof(struct NODE));
    temp->info = val;
    temp->left=temp->right=NULL;
    if(first == NULL){
        printf("Key not found!");
        return NULL;
    }else if(first->info == key){
        temp->right = first;
        first->left = temp;
        return temp;
    }else{
        cur = first;
        while(cur!=NULL && cur->info != key){
            prev = cur;
            cur = cur->right;
        }
        if(cur==NULL){
            printf("Key not found!");
            return first;
        }
        prev->right = temp;
        temp->left = prev;
        temp->right = cur;
        cur->left = temp;
        return first;
    }
}

node delete_key(node first,int key){
    node cur,prev,next;
    if(first == NULL){
        printf("Key not found!");
        return first;
    }else if(first->info==key){
        cur = first;
        first = first->right;
        if(first != NULL){
            first->left = NULL;
        }
        free(cur);
        return first;
    }else{
        cur = first;
        while(cur!=NULL && cur->info != key){
            prev = cur;
            cur = cur->right;
        }
        if(cur==NULL){
            printf("Key not found!");
            return first;
        }
        next = cur->right;
        prev->right = next;
        if(next!=NULL){
            next->left = prev;
        }
        free(cur);
        return first;
    }
}

void display(node first){
    if(first==NULL){
        printf("Empty DLL");
        return;
    }
    node cur = first;
    printf("\n--DLL--\n");
    while(cur!=NULL){
        printf("%d\t",cur->info);
        cur = cur->right;
    }
}

int main(){
    node first = NULL;
    int ch,val,key;
    printf("\n-----MENU----\n");
    printf("1.Insert_front\n2.Insert_key\n3.Delete_key\n4.Display\n");
    for(;;){
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value to be inserted:");
                scanf("%d",&val);
                first = insert_front(first,val);
                printf("Inserted\n");
                break;
            case 2:
                printf("Enter value to be inserted:");
                scanf("%d",&val);
                printf("Enter the key:");
                scanf("%d",&key);
                first = insert_key(first,val,key);
                printf("Inserted\n");
                break;
            case 3:
                printf("Enter the key:");
                scanf("%d",&key);
                first = delete_key(first,key);
                printf("Deleted\n");
                break;
            case 4:
                display(first);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}