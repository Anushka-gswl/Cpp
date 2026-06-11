#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int size = 4;
    int arr[size];
    cout<<"Enter array elements: \n";
    for( int i = 0; i < size; i++){
        cin>>arr[i];
    }

    int smallest = INT_MAX ;
    int largest = INT_MIN ;
    int smallest_idx = INT_MAX, largest_idx = INT_MIN;
    
    for (int i = 0; i < size; i++){
        if( arr[i] < smallest){
            smallest = arr[i];
            smallest_idx = i;
        }
        if( arr[i] > largest){
            largest = arr[i];
            largest_idx = i;
        }
    }
    cout<<"Minimum element is "<<smallest<<" at index "<<smallest_idx<<'\n';
    cout<<"Maximum element is "<<largest<<" at index "<<largest_idx<<'\n';

    return 0;
}