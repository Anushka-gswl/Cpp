#include <iostream>
#include <vector>
using namespace std;

int LinearSearch( vector<int> nums, int target){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;
}

int main() {
    cout<<"Enter size of vector: ";
    int n, target;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements: ";
    for(int i =0 ; i < n; i++){
        cin>>nums[i];
    }
    cout<<"Enter target element: ";
    cin>>target;
    int ans = LinearSearch(nums, target);
    if(ans == -1){
        cout<<"Element doesn't exist in vector";
    } else {
        cout<<"Target element is at "<<ans<<" index";
    }
    return 0;
}