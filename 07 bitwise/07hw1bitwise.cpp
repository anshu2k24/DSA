// //logic 1
// #include <iostream>
// using namespace std;

// int main(){
//     int n,m,r;
//     m = 0;
//     n = 1;
//     while(n != 1){
//         r = n % 2;
//         cout << "r: " << r << endl;
//         n /= 2;
//         cout << "n: " << n << endl;
//         if(r == 1){
//             m++;
//             cout << "m: " << m << endl;
//         }
//     }
//     // m = (n << 1);
//     // if(m == (n * 2)){
//         //     cout << "Power of two";
//         // }else{
//             //     cout << "Not power of two";
//             // }
//     cout << "m: " << m << endl;
//     if(m == 0){
//         cout << "Power of two";
//     }else{
//         cout << "Not power of two";
//     }
//     return 0;
// }


//logic 2
// #include <iostream>
// using namespace std;

// int main(){
//     int val,n=34;
//     val = n & (n-1);
//     if(val == 0){
//         cout << "Power of two";
//     }else{
//         cout << "Not power of two";
//     }
//     return 0;
// }

//logic 3
#include <iostream>
using namespace std;

int main(){
    int n=34,i=1,val = false;

    while(i <= n){
        if( i == n) {
            val = true;
        }
        i = i << 1;
    }
    
    if(val){
        cout << "Power of two";
    }else{
        cout << "Not power of two";
    }
    return 0;
}