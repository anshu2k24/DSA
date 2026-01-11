#include <stdio.h>

int main(){
    int m,n,nz=0;

    printf("Enter number rows:");
    scanf("%d",&m);
    printf("Enter number columns:");
    scanf("%d",&n);

    int mat[m][n];

    printf("Enter matrix:");
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0){
                nz++;
            }
        }
    }

    printf("matrix entered:\n");
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

    if(nz > ((n*m)/2)){
        printf("The matrics entered is not a sparse matrix!");
    }else{
        int s[nz+1][3];
        int sm=1;
        s[0][0]=m;
        s[0][1]=n;
        s[0][2]=nz;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(mat[i][j]!=0){
                    s[sm][0]=i;
                    s[sm][1]=j;
                    s[sm][2]=mat[i][j];
                    ++sm;
                }
            }   
        }

        printf("\nThe triple representation is:\n");
        for(int i = 0; i < (nz+1) ; i++){
                printf("%d\t%d\t%d\n",s[i][0],s[i][1],s[i][2]);
        }

        int key,found=0;
        for(;;){
            found = 0;
            printf("\nEnter element to search:");
            scanf("%d",&key);
            for(int i = 1; i < (nz+1) ; i++){
                if(key==s[i][2]){
                    printf("\nKey found:\nrow_no:%d\tcol_no:%d\tvalue:%d\n",s[i][0],s[i][1],s[i][2]);
                    found = 1;
                }
            }
            if(!found){
                printf("Key not found!");
            }
        }
    }
    return 0;
}