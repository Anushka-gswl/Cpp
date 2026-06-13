#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    int m, n;
    cout<<"Enter size of first array: ";
    cin>>m;

    vector<int> arr1(m);

    cout<<"Enter elements of first array:\n";
    for(int i = 0; i < m; i++){
        cin>>arr1[i];
    }

    int target1, target2;

    cout<<"Enter target element for first array: ";
    cin>>target1;

    cout<<"Enter size of second array: ";
    cin>>n;
    
    vector<int> arr2(n);

    cout<<"Enter elements of second array:\n";
    for(int i = 0; i < n; i++){
        cin>>arr2[i];
    }
    
    cout<<"Enter target element for second array: ";
    cin>>target2;

    int ans1 = BinarySearch(arr1, m, target1);
    int ans2 = BinarySearch(arr2, n, target2);

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