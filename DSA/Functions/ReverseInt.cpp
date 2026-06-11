#include <iostream>
using namespace std;

int Reverse(int n){
    int rev = 0;
    while(n > 0){
        int rem = n % 10;
        n /= 10;
        rev = rev*10 + rem;
    }
    return rev;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Reverse of the number is: "<<Reverse(n);
    return 0;
}