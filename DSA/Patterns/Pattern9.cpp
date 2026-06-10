#include <iostream>
using namespace std;

int main(){
    //Inverted Triangle Pattern
    /*
       11111
        2222
         333
          44
           5
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    
    for( int i = 0; i < n; i++){
        for ( int j = 0; j <i; j++){
            cout<<" ";
        }
        for( int j = 0; j < n - i; j++){
            cout<<i+1;
        }
        cout<<'\n';
    }

    //For characters
    for( int i = 0; i < n; i++){
        for ( int j = 0; j <i; j++){
            cout<<" ";
        }
        for( int j = 0; j < n - i; j++){
            cout<<(char)(i+'A');
        }
        cout<<'\n';
    }
    return 0;
}