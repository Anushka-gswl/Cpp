#include <iostream>
using namespace std;

int main(){
    //Floyd's Triangle Pattern
    /*
         1
         2 3
         4 5 6
         7 8 9 10
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    int count = 1;
    for( int i = 0; i < n; i++){
        for( int j = 0; j < i+1; j++){
            cout<<count<<" ";
            count++;
        }
        cout<<'\n';
    }
    cout<<'\n';

    //For characters
    char ch = 'A';
    for( int i = 0; i < n; i++){
        for( int j = 0; j < i+1; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<'\n';
    }
    return 0;
}