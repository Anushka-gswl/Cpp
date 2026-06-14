#include <iostream>
#include <vector>
using namespace std;

void insertionSort( vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int prev = i-1;
        while( prev >= 0 && arr[prev] > curr){  //For descending order we use - arr[prev] < curr
            arr[ prev + 1] = arr[ prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void printArray(vector<int> arr){
    for ( int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    vector<int> arr = { 1,6,3,5,9,7,3,2,6};

    insertionSort(arr);
    printArray(arr);
    return 0;
}