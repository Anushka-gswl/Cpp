#include <iostream>
#include <algorithm>
using namespace std;

void Reverse( int arr[], int size){
    int i = 0, j = size-1;
    while( i < j){
        swap(arr[i], arr[j]);
        i++, j--;
    }
    return;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int size = 10;

    Reverse(arr, size);
    
    for( int i =0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}