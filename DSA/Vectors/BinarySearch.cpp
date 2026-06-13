#include <iostream>
#include <vector>
using namespace std;

//Without Recursion - More Optimized than recursion as : TC => O(log n), SC=> O(n)
int BinarySearch(vector<int> arr, int n, int target){
    int st = 0, end = n-1;
    while( st <= end){
        int mid = st + (end - st) / 2;  //Optimized formula for (st + end) / 2
        if( target == arr[mid]){
            return mid;
        } else if( target > arr[mid]){
            st = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    return -1;
}

//With Recursion - Less Optimized due to recursive call stack in memory: TC => O(log n), SC=> O(log n)
int BinarySrch( vector<int> arr, int target, int st, int end){
    int mid = st + (end - st) / 2;
    while( st <= end){
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

    int ans1 = BinarySearch(arr, n, target);
    int ans2 = BinarySrch(arr, target, 0, n-1);

    if(ans1 == -1){
        cout<<"Element doesn't exist in the array"<<'\n';
    } else{
        cout<<"Target element is at "<<ans1<<" index.\n";
    }
    if(ans2 == -1){
        cout<<"Element doesn't exist in the array"<<'\n';
    } else{
        cout<<"Target element is at "<<ans2<<" index.\n";
    }
    return 0;
}