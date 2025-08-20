#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 1; i<=n;i++){
        //pre-spaces
        for(int j = 1;j<=n-i;j++){
                cout<<" ";
        }
        //forward-numbers
        for(int k = 1;k<=i;k++){
                cout<<k;
        }
        //backward-numbers
        for(int k = i-1;k>0;k--){
                cout<<k;
        }
        //post-spaces
        for(int j = 1;j<=n-i;j++){
                cout<<" ";
        }
       cout<<endl;
    }
    return 0;
}