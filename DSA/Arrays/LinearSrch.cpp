#include <iostream>
using namespace std;

int LinearSrch(int arr[], int size, int target){
    int idx = -1;
    for( int i = 0; i < size; i++){
        if(arr[i] == target){
            idx = i;
        }
    }
    return idx;
}

int main(){
    int arr[] = {1,2,3,4,5,54,7,38};
    int size = 8;
    int target;
    cout<<"Enter target element: ";
    cin>>target;

    int idx = LinearSrch( arr, size, target);

    if( idx == -1){
        cout<<"Target element does not exist in the array\n";
    } else {
        cout<<"The target element is at "<<idx<<" index\n";
    }
    return 0;
}