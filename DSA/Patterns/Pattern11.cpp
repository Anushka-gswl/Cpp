#include <iostream>
using namespace std;

int main() {
    //Hollow Diamond Pattern
    /*
                 *
              *     *
           *           *
        *                 *
           *           *
              *     *
                 *
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    for (int i = 0; i < n; i++){
        for ( int j = n-i-1; j > 0; j--){
            cout<<"  ";
        }
        cout<<"*"<<" ";
        for ( int j = 0; j < 2*i-1; j++){
            cout<<"  ";
        }
        if(i!=0){
            cout<<"*"<<" ";
        }
        cout<<'\n';
    }

    for ( int i = 0; i < n-1; i++){
        for ( int j = 0; j < i+1; j++){
            cout<<"  ";
        }
        cout<<"*"<<" ";
        if(i!=n-2){
            for ( int j = 0; j < 2*(n-i-2)-1; j++){ //2*(n-2-i)-1 = 2*(n-i)-5 is the number of spaces in the middle of the pattern
                cout<<"  ";
            }
            cout<<"*"<<" ";
        }
        cout<<'\n';
    }
    return 0;
}