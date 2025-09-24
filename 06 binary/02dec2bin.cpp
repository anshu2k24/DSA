#include <iostream>
using namespace std;

int dec2bin ( int n ) {
    int dec = 0, place = 1 , r;
    while(n){
        r = n % 10; // gives us the last digit of the binary
        dec += r * place; // adds to the decimal number
        n /= 10; // new n
        place *= 2; // power function
    }
    return dec;
}

int main(){
    cout << dec2bin(101110) << endl;
    return 0;
}