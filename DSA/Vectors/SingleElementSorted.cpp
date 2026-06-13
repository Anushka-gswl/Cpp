#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {  // TC => O(log n)
    if( nums.size() == 1){
        return nums[0];
    }
    int st = 0, end = nums.size() - 1;
    while(st <= end){
        int mid = st + (end - st) / 2;
        if( mid == 0 && nums[mid] != nums[mid + 1]){
            return nums[mid];
        }
        if( mid == nums.size() - 1 && nums[mid] != nums[mid - 1]){
            return nums[mid];
        }
        if( nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        if( mid % 2 ==0){
            if(nums[mid] == nums[mid - 1]){
                end = mid - 1;
            } else{
                st = mid + 1;
            }
        } else{
            if(nums[mid] == nums[mid - 1]){
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
    
    int ans = singleNonDuplicate(arr);
    
    if(ans == -1){
        cout<<"No single element exists."<<'\n';
    } else{
        cout<<"Single element is:  "<<ans;
    }
    return 0;
}