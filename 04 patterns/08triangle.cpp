#include <iostream>
using namespace std;

// int main(){
//     int n,c=1;
//     cin>>n;
//     for(int i = 1; i<=n;i++){
//         for(int j = 0;j<i;j++){
//             cout<<c<<" ";
//             c++;
//         }
//        cout<<endl;
//     }
//     return 0;
// }
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << (((i * (i - 1)) / 2) + 1 + j) << " ";
        }
        cout << endl;
    }
    return 0;
}