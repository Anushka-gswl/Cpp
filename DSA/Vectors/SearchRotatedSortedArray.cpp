#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> nums, int target) {
    int st = 0, end = nums.size() - 1;

    while( st <=end){
        int mid = st + ( end - st) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if( nums[st] <= nums[mid]){
            if( nums[st] <= target && target <= nums[mid]){
                end = mid - 1;
            } else{
                st = mid + 1;
            }
        } else{
            if( nums[mid] <= target && target <= nums[end]){
                st = mid + 1;
            } else{
                end = mid - 1;
            }
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

    int ans = search(arr, target);
    

    if(ans == -1){
        cout<<"Element doesn't exist in the array"<<'\n';
    } else{
        cout<<"Target element is at "<<ans<<" index.\n";
    }
    
    return 0;
}