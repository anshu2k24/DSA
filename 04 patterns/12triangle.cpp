#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    //top
    for(int i = 1;i<=n;i++){
        //stars
        for(int j = 1; j<=i;j++){
            cout<<"*";
        }
        //space
        for(int k = 1;k<=2*(n-i);k++){
            cout<<" ";
        }
        //stars
        for(int j = 1; j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    //bottom
    for(int i = n;i>0;i--){
        //stars
        for(int j = 1; j<=i;j++){
            cout<<"*";
        }
        //space
        for(int k = 1;k<=2*(n-i);k++){
            cout<<" ";
        }
        //stars
        for(int j = 1; j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}