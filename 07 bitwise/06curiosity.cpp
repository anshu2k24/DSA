#include <iostream>
using namespace std;

int main(){
    long long int c = 1;
    long long int sum = 0;
    for(int i = 0 ; i < 32 ; i++){
        sum += c;
        c*=2; 
    }
    cout << sum;
    return 0;
}