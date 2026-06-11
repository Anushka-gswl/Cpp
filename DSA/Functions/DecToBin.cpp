#include <iostream>
using namespace std;

int binary(int n){
    int ans = 0;
    int pow = 1;
    while(n>0){
        int rem = n % 2;
        n /= 2;
        ans += rem * pow;
        pow *= 10;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a decimal number: ";
    cin>>n;
    cout<<"Binary Numbedr is: "<<binary(n)<<'\n';
    return 0;
}