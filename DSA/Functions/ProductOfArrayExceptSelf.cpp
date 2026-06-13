#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach - TC => O(n^2)
vector<int> productExceptSelf1(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    for( int i =0; i < nums.size(); i++){
        for( int j =0; j < nums.size(); j++){
            if( i != j){
                ans[i] *= nums[j];
            } 
        }
    }
    return ans;
}

//Optimized Approach - TC => O(n) , SC => O(n)
vector<int> productExceptSelf2(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    for( int i =1; i < n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    for( int j = n-2; j>=0; j--){
        suffix[j] = suffix[j+1] * nums[j+1];
    }
    for( int i =0; i < n; i++){
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

//Most Optimized Approach - TC => O(n) , SC => O(1)
vector<int> productExceptSelf3(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    for( int i =1; i < n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;
    for( int i = n-2; i>=0; i--){
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }
    return ans;
}

int main() {
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter array elements:\n";
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    vector<int>ans1 = productExceptSelf1( nums);
    vector<int>ans2 = productExceptSelf2( nums);
    vector<int>ans3 = productExceptSelf3( nums);

    for(int a : ans1){
        cout<<a<<" ";
    }
    cout<<'\n';
    for(int a : ans2){
        cout<<a<<" ";
    }
    cout<<'\n';
    for(int a : ans3){
        cout<<a<<" ";
    }
    return 0;
}