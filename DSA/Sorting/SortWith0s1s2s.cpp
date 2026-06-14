#include <iostream>
#include <vector>
using namespace std;

//Brute Force (TC => O(n log n)) - In-built sort(arr.begin(), arr.end()) function

//Optimized Approach - TC => O(n) with two passes
void sort1( vector<int> &arr){
    int n = arr.size();
    int count0 = 0, count1 = 0, count2 = 2;
    int idx = 0;

    //O(n)
    for( int i =0; i < n; i++){
        if( arr[i] == 0){
            count0++;
        } else if( arr[i] == 1){
            count1++;
        } else{
            count2++;
        }
    }

    //O(n)
    for( int i = 0; i < count0; i++){
        arr[idx++] = 0;
    }
    for( int i = 0; i < count1; i++){
        arr[idx++] = 1;
    }
    for( int i = 0; i < count2; i++){
        arr[idx++] = 2;
    }
}

//Optimal Approach - Diutch National Flag Algorithm - O(n) with single pass
void sort2( vector<int> &arr){
    int n = arr.size();
    int mid = 0, high = n - 1, low = 0;
    while( mid <= high){
        if( arr[mid] == 0){
            swap( arr[low], arr[mid]);
            low++;
            mid++;
        } else if ( arr[mid] == 1){
            mid++;
        } else{
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

void printArray(vector<int> arr){
    for ( int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    vector<int> arr = {0,1,2,1,2,0,2,1,0,1,2,2,1,0};
    sort1(arr);
    printArray(arr);
    sort2(arr);
    printArray(arr);
    return 0;
}