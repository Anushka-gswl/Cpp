#include <iostream>
using namespace std;

bool IsPrime( int m) {
    bool isPrime = true;
    for ( int i=2; i*i <= m; i++){
        if(m%i == 0){
            isPrime = false;
            return isPrime;
        }
    }
    return isPrime;
}

void prime1toN( int n){
    for( int i=2; i < n; i++){
        if(IsPrime(i)){
            cout<<i<<" ";
        }
    }
    return;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    prime1toN(n);
    return 0;
}