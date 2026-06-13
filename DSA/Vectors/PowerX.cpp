#include <iostream>
#include <vector>
using namespace std;

//Optimal Approach
double PowX( int x, int n){
    if( n == 0){
        return 1;
    }
    if( x == 1){
        return 1;
    }
    if( x == -1 && n % 2 == 0){
        return 1;
    }
    if( x == -1 && n % 2 != 0){
        return -1;
    }
    if( x == 0){
        return 0;
    }
    int binform = n;
    double ans = 1.0;
    
    if( n < 0){
        binform = -binform;
        x = 1/x;
    }

    while( binform > 0){
        if(binform % 2 == 1){
            ans *= x;
        }
        x *= x;
        binform /= 2;
    }
    return ans;
}


int main(){
    int x,n;
    cout<<"Enter a number: ";
    cin>>x;
    cout<<"Enter the required power: ";
    cin>>n;
    double ans = PowX(x,n);
    cout<<"The answer is: "<<ans;
    return 0;
}