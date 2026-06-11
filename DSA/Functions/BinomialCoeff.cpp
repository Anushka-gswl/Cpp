#include <iostream>
using namespace std;

int Factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact*=i;
    }
    return fact;
}

int nCr(int n, int r) {
    return Factorial(n) / (Factorial(r) * Factorial(n - r));
}

int main() {
    int n, r;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of r: ";
    cin>>r;

    cout<<"The binomial coefficient C("<<n<<", "<<r<<") is: "<<nCr(n, r);
    
    return 0;
}