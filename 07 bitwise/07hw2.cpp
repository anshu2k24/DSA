#include <iostream>
using namespace std;

int rev(int n){
    int r=0,rem;
    while(n){
        rem = n % 10;
        n /= 10;
        r = (r * 10) + rem;
    }
    return r;
}

int main(){
    int m = 234;
    cout << rev(m);
    return 0;
}