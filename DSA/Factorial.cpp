#include <iostream>
using namespace std;

int main () {
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int fact=1;
    
    //Using for loop to calculate factorial
    for ( int i = 1; i <= n; i++ ){
        fact*=i;
    }
    cout<<"Factorial of "<<n<<" is: "<<fact<<'\n';

    //Using while loop to calculate factorial
    int j=1, fact1=1;
    while (j<=n){
        fact1*=j;
        j++;
    }
    cout<<"Factorial of "<<n<<" is: "<<fact1<<'\n';
    return 0;
}