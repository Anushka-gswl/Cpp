#include <iostream>
using namespace std;

int main () {
    //Square Pattern
    /*1 2 3
      4 5 6
      7 8 9*/

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    //Method 1
    for ( int i=0;i<n;i++) {
        for( int j=0;j<n;j++) {
            cout<<j+1+i*n<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //Method 2
    int count = 1;
    for ( int i=0;i<n;i++) {
        for( int j=0;j<n;j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For characters
    char ch='A';
    for ( int i=0;i<n;i++) {
        for ( int j=0;j<n;j++) {
            cout<<ch<<" ";
            ch++;
        }
        cout<<'\n';
    }
    return 0;
}