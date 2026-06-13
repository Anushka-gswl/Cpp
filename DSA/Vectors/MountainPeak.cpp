#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) { //TC => O(log n)
    int st = 1, end = arr.size() - 2;
    while( st <= end){
        int mid = st + (end - st) / 2;
        if( arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        } else if( arr[mid] > arr[mid - 1]){
            st = mid + 1;
        } else{
            end = mid -1;
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

    int ans = peakIndexInMountainArray(arr);

    if(ans == -1){
        cout<<"Peak element doesn't exist"<<'\n';
    } else{
        cout<<"Peak element is at "<<ans<<" index.\n";
    }
    
    return 0;
}