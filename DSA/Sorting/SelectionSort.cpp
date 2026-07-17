#include <iostream>
#include <vector>
using namespace std;

void selectionSort( vector<int> &arr){
    int n = arr.size();
    for( int i = 0; i< n - 1; i++){
        int smallest_idx = i;
        for( int j = i + 1; j < n; j++){
            if( arr[j] < arr[smallest_idx]){  //for descending order array we use - ( arr[j] > arr[largest_idx])
                smallest_idx = j;
            }
        }
        swap(arr[i], arr[smallest_idx]);
    }
}

void printArray(vector<int> arr){
    for ( int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    vector<int> arr = { 1,6,3,5,9,7,3,2,6};

    selectionSort(arr);
    printArray(arr);
    return 0;
}