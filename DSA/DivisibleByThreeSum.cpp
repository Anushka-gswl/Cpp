#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 3 ==0){
            sum+=i;
        }
    }
    cout<<"Sum of numbers divisible by 3: "<<sum<<'\n';
    return 0;
}