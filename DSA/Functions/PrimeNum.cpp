#include <iostream>
using namespace std;

void IsPrime( int n) {
    for ( int i=2; i*i<n; i++){
        if(n%i==0){
            cout<<"Not a prime number";
            return;
        }
    }
    cout<<"Prime Number";
    return;
}
int main() {
    IsPrime(17);
    return 0;
}