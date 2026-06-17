#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> arr, int n){ //TC => O(n), SC => O(n)
    if(n == 0 || n == 1){
        return true;
    }
    return (arr[n - 1] >= arr[n - 2]) && isSorted(arr, n - 1);
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bool ans = isSorted(arr, n);
    if(ans){
        cout << "Array is sorted";
    } else{
        cout << "Array is not sorted";
    }
    return 0;
}