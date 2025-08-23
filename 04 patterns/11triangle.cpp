#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    //upper triangle
    for(int i = 1; i<=n;i++){
        //spaces
        for(int j = 1;j<=n-i;j++){
            cout<<" ";
        }

        //1st star
        cout<<"*";

        //middle-spaces
        for(int k=1;k<=(2*i)-3;k++){
            cout<< " ";
        }

        if(i!=1 && i!=(n*2-1)){
            cout<<"*";
        }
        cout<<endl;
    }

    //bottom triangle
    for(int i = n-1; i>0;i--){
        //spaces
        for(int j = 1;j<=n-i;j++){
            cout<<" ";
        }

        //1st star
        cout<<"*";

        //middle-spaces
        for(int k=1;k<=(2*i)-3;k++){
            cout<<" ";
        }

        if(i!=1 && i!=(n*2-1)){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}