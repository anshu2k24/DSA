// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n;
    m=n;
    for(int i = 1 ; i <=n ; i++){
        for(int j = 1; j <=i ; j++){
            cout << "*";
        }
        for(int s = 1; s <= ((2*m)-3) ; s++){
            cout << " ";
        }
        for(int j = 1; j <=i ; j++){
            cout << "*";
        }
        cout << endl;
        m--;
    }
    m=1;
    for(int i = n ; i >=1 ; i--){
        for(int j = 1; j <=i ; j++){
            cout << "*";
        }
        for(int s = 1; s <= ((2*m)-3) ; s++){
            cout << " ";
        }
        for(int j = 1; j <=i ; j++){
            cout << "*";
        }
        cout << endl;
        m++;
    }
    return 0;
}