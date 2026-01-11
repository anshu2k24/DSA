#include <stdio.h>
#include <stdlib.h>

struct emp{
    int id;
    char name[20];
    float sal;
};

void main(){
    struct emp e[10];
    int n;
    printf("Enter no. of employees:");
    scanf("%d",&n);

    printf("Enter the employee details:\n");
    for(int i = 0; i<n; i++){
        printf("ID,Name and salary for emp %d:\n",i+1);
        scanf("%d %s %f",&e[i].id,&e[i].name,&e[i].sal);
    }

    int key,found =0;
    printf("\n------MENU------\n1.Search\n2.Display\n3.Exit\n");
    for(;;){
        int ch;
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                found = 0;
                printf("\nEnter employee ID to search:");
                scanf("%d",&key);
                for(int i = 0; i<n; i++){
                    if(e[i].id==key){
                        printf("\nFound employee:\nID: %d\nName: %s\nSalary: %f\n",e[i].id,e[i].name,e[i].sal);
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    printf("\nEmployee with ID : %d not found\n",key);
                }
                break;
            case 2:
                printf("\nThe employees are:\n");
                printf("ID\tName\tsalary\n");
                for(int i = 0; i<n; i++){
                    printf("%d\t%s\t%f\n",e[i].id,e[i].name,e[i].sal);
                }
                printf("\n");
                break;
            default:
                exit(0);
        }
        
    }
}