#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1, i = m - 1, j = n - 1;
    while(i >= 0 && j >= 0){
        if( nums1[i] >= nums2[j]){
            nums1[idx--] = nums1[i--];
        } else{
            nums1[idx--] = nums2[j--];
        }
    }
    while(j >= 0){
        nums1[idx--] = nums2[j--];
    }
}

void printArray(vector<int> arr){
    for ( int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    vector<int> arr1 = {1,4,5,0,0,0};
    vector<int> arr2 = {2,6,7};
    merge(arr1, 3, arr2, 3);
    printArray(arr1);
    return 0;
}