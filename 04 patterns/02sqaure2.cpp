#include <iostream>
using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     for(int i = 1; i<=n*n;i++){
//         // for(int j = 1;j<=3*i;j++){
//         //     cout<<j;
//         // }
//         cout<<i;
//         if(i%n==0){
//             cout<<endl;
//         }
//     }
//     return 0;
// }


//more DSA style is below :
int main(){
    int n,c=1;
    cin>>n;
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<c;
            c++;
        }
       cout<<endl;
    }
    return 0;
}