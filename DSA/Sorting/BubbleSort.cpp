#include <iostream>
#include <vector>
using namespace std;

void bubbleSort( vector<int> &arr){
    int n = arr.size();
    for( int i = 0; i < n - 1; i++){
        bool isSwap = false;
        for( int j = 0; j < n - i -1; j++){
            if(arr[j] > arr[j + 1]){ // for descending order we use - (arr[j] < arr[j + 1])
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if (!isSwap ){
            return;
        }
    }
}

void printArray(vector<int> arr){
    for ( int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    vector<int> arr = { 1,6,3,5,9,7,3,2,6};

    bubbleSort(arr);
    printArray(arr);
    return 0;
}