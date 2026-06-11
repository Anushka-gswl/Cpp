#include <iostream>
using namespace std;

int SumN(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum+=i;
    }
    return sum;
}

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"The sum of first "<<n<<" natural numbers is: "<<SumN(n);
    
    return 0;
}