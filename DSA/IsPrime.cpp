#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    bool isPrime1=true;

    //Method 1
    for(int i=2; i<=n-1; i++) {
        if(n%i==0){
            isPrime1 = false;
            break;
        }
    }

    if(isPrime1){
        cout<<"The number is prime."<<'\n';
    } else{
        cout<<"The number is not prime."<<'\n';
    }

    //Method 2
    bool isPrime2 = true;
    for(int i=2; i<=n/2; i++) {
        if(n%i==0){
            isPrime2 = false;
            break;
        }
    }

    if(isPrime2){
        cout<<"The number is prime."<<'\n';
    } else{
        cout<<"The number is not prime."<<'\n';
    }

    //Method 3
    bool isPrime3 = true;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0){
            isPrime3 = false;
            break;
        }
    }

    if(isPrime3){
        cout<<"The number is prime."<<'\n';
    } else{
        cout<<"The number is not prime."<<'\n';
    }
    return 0;
}