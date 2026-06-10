#include <iostream>
using namespace std;

int main () {

    //Square Pattern
    /*1 2 3 4
      1 2 3 4
      1 2 3 4
      1 2 3 4*/
    
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    for ( int i = 1; i <= n ; i++ ){
        for ( int j = 1; j <= n; j++ ){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For stars
    for ( int i = 1; i <= n ; i++ ){
        for ( int j = 1; j <= n; j++ ){
            cout<<"*"<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For alphabets - Method 1 - using character literals
    for ( int i=1; i<=n; i++ ){
        for ( char j='A'; j<=('A'+n-1); j++ ){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For alphabets - Method 2 - using numeric values
    for ( int i=1; i<=n; i++ ){
        for ( int j=65; j<=(65+n-1); j++ ){
            cout<<(char)j<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For alphabets - Method 3 - using ASCII values and implicit conversion
    for ( int i=1; i<=n; i++ ){
        for ( int j=0; j<n; j++ ){
            cout<<(char)(65+j)<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For alphabets - Method 4 - using ASCII values and implicit conversion with character literals
    for ( int i=1; i<=n; i++ ){
        for ( int j=0; j<n; j++ ){
            cout<<(char)('A'+j)<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For alphabets - Method 5 - using a variable to keep track of the current character
    for ( int i = 1; i <= n ; i++ ){
        char ch='A';
        for ( int j = 1; j <= n; j++ ){
            cout<<ch<<" ";
            ch++;
        }
        cout<<'\n';
    }
    return 0;
}