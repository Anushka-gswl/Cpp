#include <iostream>
using namespace std;

bool Power2(int n){
    int i=n;
    bool ans = false;
    while(i > 0){
        if(n>>i == 1){
            ans = true;  //Incorrect code
            return ans;
        }
        i /= 2;
        return ans;
    }
}

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if(Power2(n)){
        cout<<"The number is a power of 2"<<'\n';
    } else {
        cout<<"The number is not a power of 2"<<'\n';
    }
    return 0;
}