#include <iostream>
using namespace std;

int Fibonacci(int n) { // TC => O(2^n), SC => O(n)
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"The fibonacci of "<<n<<" is:\n";
    for( int i = 0; i < n; i++){
        cout << Fibonacci(i) <<" ";
    }
    
    return 0;
}