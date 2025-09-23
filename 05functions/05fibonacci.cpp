#include <iostream>
using namespace std;

 void fib(int n){
    int f1 = 0, f2 = 1,f3;
    if (n <=0 ) {
        return;
    }else if (n == 1) {cout<<f1 << " ";
    }else if (n == 2) {cout << f1 << " " << f2 << " ";
    }else{
        cout << f1 << " " << f2 << " ";
         for (int i = 2; i <n ; i++){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
            cout << f3 << " ";
        }
    }

}

int main(){
    int n=8;
    fib(n);
    return 0;
}