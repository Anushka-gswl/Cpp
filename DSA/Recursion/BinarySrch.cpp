#include <iostream>
#include <vector>
using namespace std;

int BinarySrch( vector<int> arr, int target, int st, int end){ //TC => O(log n), SC => O(log n)
    int mid = st + (end - st) / 2;
    if( st <= end){
        if ( target == arr[mid]){
            return mid;
        } else if( target > arr[mid]){
            return BinarySrch(arr, target, mid + 1, end);
        } else{
            return BinarySrch( arr, target, st, mid - 1);
        }
    }
    return -1; 
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements of array:\n";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int target;

    cout<<"Enter target element: ";
    cin>>target;

    int ans = BinarySrch(arr, target, 0, n-1);

    if(ans == -1){
        cout<<"Element doesn't exist in the array"<<'\n';
    } else{
        cout<<"Target element is at "<<ans<<" index.\n";
    }
    return 0;
}