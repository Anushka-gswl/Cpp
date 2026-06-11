#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int MinIdx(int arr[], int n){
    int smallest_idx = 0;
    for (int i = 0; i < n; i++){
        if( arr[i] < arr[smallest_idx]){
            smallest_idx = i;
        }
    }
    return smallest_idx;
}

int MaxIdx(int arr[], int n){
    int largest_idx = 0;
    for (int i = 0; i < n; i++){
        if( arr[i] > arr[largest_idx]){
            largest_idx = i;
        }
    }
    return largest_idx;
}

void SwapMinMax(int arr[], int smallest_idx, int largest_idx){
    swap(arr[smallest_idx], arr[largest_idx]);
    return;
}
int main(){
    int arr[5];
    cout<<"Enter array elements: ";
    for( int i = 0; i < 5; i++){
        cin>>arr[i];
    }
    int smallest_idx = MinIdx(arr,5);
    int largest_idx = MaxIdx(arr,5);
    SwapMinMax(arr, smallest_idx, largest_idx);
    for( int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}