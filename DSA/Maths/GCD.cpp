#include <iostream>
using namespace std;

int gcd(int a, int b){
    while( a > 0 && b > 0){
        if( a > b){
            a %= b;
        } else{
            b %= a;
        }
    }
    if( a == 0){
        return b;
    } else{
        return a;
    }
}

int gcdRec(int a, int b){
    if(b == 0){
        return a;
    }
    gcdRec(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcdRec(a,b);
}

int main() {
    cout << gcd(20,28) << '\n';
    cout << gcdRec(0,24) << '\n';
    cout<< lcm(20,28);
    return 0;
}