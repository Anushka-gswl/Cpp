#include <iostream>
using namespace std;

int main (){
    //Pattern of equal number of columns in each row
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns in each row: ";
    cin>>m;

    for ( int i=1; i<=n; i++){
        for ( int j=1; j<=m; j++){
            cout<<"*"<<" ";
        }
        cout<<'\n';
    }
    return 0;
}