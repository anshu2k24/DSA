#include <iostream>
using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     for(int i = 1; i<=n;i++){
//         for(int j = 1;j<=n;j++){
//             if(j<i){
//                 cout<<" ";
//             }else{
//                 cout<<i;
//             }
//         }
//        cout<<endl;
//     }
//     return 0;
// }

//better for DSA problem approach

int main(){
    int n;
    cin>>n;
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=i-1;j++){
                cout<<" ";
        }
        for(int k = 1;k<=n-i+1;k++){
                cout<<i;
        }
       cout<<endl;
    }
    return 0;
}