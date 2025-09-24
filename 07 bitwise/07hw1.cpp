#include <iostream>
using namespace std;

int main(){
    int n = 2,i=0,r;
    while(n){
        r = n % 2;
        n /= 2;
        i++;
    }
    if(r==1){
        cout << "not power of 2" ;
    }else{
        cout << "power of 2";
    }
    return 0;
}