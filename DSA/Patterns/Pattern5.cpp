#include <iostream>
using namespace std;

int main () {
    //Triangle Pattern
    /*
       1
       2 2
       3 3 3
       4 4 4 4
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < i+1; j++){
            cout<<i+1<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For characters
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < i+1; j++){
            cout<<(char)(i+'A')<<" ";
        }
        cout<<'\n';
    }
    return 0;
}