#include <iostream>
using namespace std;

void Intersection( int arr1[], int sz1, int arr2[], int sz2){
    for( int i =0; i < sz1; i++){
       for(int j = 0; j < sz2; j++){
        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
        }
       } 
    }
    return;
}

int main() {
    int arr1[3], arr2[4];
    cout<<"Enter elements of array 1: ";
    for(int i = 0; i < 3; i++){
        cin>>arr1[i];
    }
    cout<<"Enter elements of array 2: ";
    for(int i = 0; i < 4; i++){
        cin>>arr2[i];
    }
    Intersection(arr1,3,arr2,4);
    return 0;
}