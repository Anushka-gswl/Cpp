#include <iostream>
using namespace std;

int main() {
    //Pyramid Pattern
    /*
                 1
              1  2  1
           1  2  3  2  1
        1  2  3  4  3  2  1
    */
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            cout<<"  ";
        }
        for( int j = 0; j < i+1; j++){
            cout<<j+1<<" ";
        }
        for(int j = i; j > 0; j--){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    return 0;
}