#include <iostream>
// #include <cmath>
using namespace std;

int main(){
    int n,bin,r,i,place;
    i = 0;
    n = 10;
    bin = 0;
    place = 1;
    while(n){
        r = n % 2;
        // bin += pow(10,i) * r ; 
        bin += place * r ; 
        n /= 2;
        i++;
        place *= 10;
    }
    cout << bin;
    return 0;
}