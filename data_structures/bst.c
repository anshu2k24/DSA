#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int info;
    struct NODE *left;
    struct NODE *right;
};

typedef struct NODE * node;

node insert(node root,int val){
    node cur,prev;
    node temp = (node) malloc (sizeof(struct NODE));
    temp->info = val;
    temp->left=temp->right=NULL;
    if(root == NULL){
        // root = temp;
        return temp;
    }else{
        cur = root;
        while(cur!=NULL){
            prev = cur;
            if(val < cur->info){
                cur = cur->left;
            }else if(val > cur->info){
                cur = cur->right;
            }
        }
        if(val < prev->info){
            prev->left = temp;
        }else if(val > prev->info){
            prev->right = temp;
        }else{
            printf("Already existing value is not permitted!");
        }
        return root;
    }
}

void preorder(node root){
    if(root!=NULL){
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}
void postorder(node root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}

int main(){
    node root = NULL;
    printf("\n-----MENU-----\n");
    printf("1.Insert\n2.PreOrder\n3.InOrder\n4.Postorder\n");
    int ch,val;
    for(;;){
        printf("Enter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Insert value:");
                scanf("%d",&val);
                root = insert(root,val);
                printf("Inserted value!\n");
                break;
            case 2:
                printf("\nPre-Order:\n");
                preorder(root);
                printf("\n---End----\n");
                break;
            case 3:
                printf("\nIn-Order:\n");
                inorder(root);
                printf("\n---End----\n");
                break;
            case 4:
                printf("\nPost-Order:\n");
                postorder(root);
                printf("\n---End----\n");
                break;
        }
    }
}