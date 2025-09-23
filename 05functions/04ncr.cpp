#include <iostream>
using namespace std;

int factorial(int n){
    int prod = 1;
    for(int i = 1; i <=n ; i++){
        prod *= i;
    }
    return prod;
}

int main(){
    int n = 6, r= 3;
    cout << factorial(n)/((factorial(r))*(factorial(n-r))) << endl;
    return 0;
}