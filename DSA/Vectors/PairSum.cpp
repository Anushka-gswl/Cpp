#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach
vector<int> PairSum(vector <int> nums, int n, int target){
    vector<int> ans;
    for( int i = 0; i < n; i++){
        for( int j = i+1; j < n; j++){
            if( nums[i] + nums [j] == target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }
        }
    }
    return ans;
}

//Two Pointer Approach - Optimized Solution
vector<int> PSum( vector<int> nums, int n, int target){
    vector<int> ans;
    int i =0, j = n - 1;
    while(i < j){
        if( nums[i] + nums[j] > target){
            j--;
        } else if(nums[i] + nums[j] < target){
            i++;
        } else{
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }
    }
    return ans;
}
int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array:\n";
    for( int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter Target Sum: ";
    cin>>target;
    vector<int> ans1 = PairSum(nums, n, target);
    cout<<"The pair having sum equal to the target is: ("<<ans1[0]<<", "<<ans1[1]<<")\n";
    vector<int> ans2 = PSum(nums, n, target);
    cout<<"The pair having sum equal to the target is: ("<<ans2[0]<<", "<<ans2[1]<<")\n";
    return 0;
}