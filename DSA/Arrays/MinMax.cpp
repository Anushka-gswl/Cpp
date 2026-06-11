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

    for( int i = 0; i < size; i++){
        smallest = min (smallest, arr[i]);
        largest = max (largest, arr[i]);
    }

    cout<<"Minimum element is: "<<smallest<<'\n';
    cout<<"Maximum element is: "<<largest<<'\n';
    return 0;
}