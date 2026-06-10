#include <iostream>
using namespace std;

int main(){
    //Triangle Pattern
    /*
       1
       1 2
       1 2 3
       1 2 3 4
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    for( int i = 0; i < n; i++){
        for( int j = 0; j < i+1; j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';
    }
    return 0;
}