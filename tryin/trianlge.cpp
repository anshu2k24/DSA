// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n;
    m = n;
    for(int i = 1; i <= n ; i++){
        for(int a = 1; a <= (m-i) ; a++){
            cout << " ";
        }
        for(int j = 1 ; j <= i ; j++){
            cout<<"*"<<" ";
        }
        for(int a = 1; a <= (m-i) ; a++){
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}