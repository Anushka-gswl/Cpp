#include <iostream>
using namespace std;

int main(){
    //Reversed Triangle Pattern
    /*
         1
         2 1
         3 2 1
         4 3 2 1
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    for( int i = 0; i < n; i++){
        for( int j = i; j >= 0; j--){
            cout<<j+1<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For characters
    for( int i = 0; i < n; i++){
        for( int j = i; j >= 0; j--){
            cout<<(char)(j+'A')<<" ";
        }
        cout<<'\n';
    }
    return 0;
}