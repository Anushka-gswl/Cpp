#include <iostream>
#include <vector>
using namespace std;

bool isArmstrong( int n){
    int a = n;
    int cubeSum = 0;
    while( n > 0){
        int rem = n % 10;
        cubeSum += rem * rem * rem;
        n /= 10;
    }
    if(cubeSum == a){
        return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    if(isArmstrong(n)){
        cout<<"It is an armstrong number.";
    } else{
        cout<<"Not an armstrong number.";
    }


    return 0;
}