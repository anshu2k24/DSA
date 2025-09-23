#include <iostream>
using namespace std;

double min(double a, double b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}

int main(){
    cout << min(2.4,3.5) <<endl;
    return 0;
}