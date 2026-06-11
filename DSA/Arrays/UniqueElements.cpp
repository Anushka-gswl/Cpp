#include <iostream>
using namespace std;

void UniqueEl(int arr[], int n){
    for(int i = 0; i < n; i++){
        bool unique= true;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j] && i != j){
                unique = false;
                break;
            }
        }
        if( unique){
            cout<<arr[i]<<" ";
        }
    }
    return;
}

int main() {
    int arr[10];
    cout<<"Enter array elements: ";
    for( int i = 0; i < 10; i++){
        cin>>arr[i];
    }
    UniqueEl(arr,10);
    return 0;
}