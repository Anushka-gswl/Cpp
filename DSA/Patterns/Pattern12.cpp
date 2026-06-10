#include <iostream>
using namespace std;

int main() {
    //Butterfly Pattern
    /*
         *             *
         * *         * *
         * * *     * * *
         * * * * * * * *
         * * *     * * *
         * *         * *
         *             *
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    for ( int i = 0; i < n; i++){
        for ( int j = 0; j < i+1; j++){
            cout<<"*"<<" ";
        }
        for ( int j = 0; j < 2*(n-i-1); j++){
            cout<<"  ";
        }
        for ( int j = 0; j < i+1; j++){
            cout<<"*"<<" ";
        }
        cout<<'\n';
    }
    for ( int i = 0; i < n; i++){
        for ( int j = 0; j < n-i; j++){
            cout<<"*"<<" ";
        }
        for ( int j = 0; j < 2*i; j++){
            cout<<"  ";
        }
        for ( int j = 0; j < n-i; j++){
            cout<<"*"<<" ";
        }
        cout<<'\n';
    }
    return 0;
}