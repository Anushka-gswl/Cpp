#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//Brute Force Approach
int MaxSubarraySum( vector<int>nums, int n){
    int maxSum = INT_MIN;
    for(int st = 0; st < n; st++){
        int currSum = 0;
        for(int end = st; end <n; end++){
            currSum += nums[end];
            maxSum = max (maxSum, currSum);
        }
    }
    return maxSum;
}
//Kadane's Algorithm
int KadaneAlgo(vector<int>nums, int n){
    int maxSum = INT_MIN, currSum = 0;
    for(int i = 0; i < n; i++){
        currSum += nums[i];
        maxSum = max ( maxSum, currSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array:\n";
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int maxSum1 = MaxSubarraySum(nums,n);
    cout<<"Maximum Subarray Sum is: "<<maxSum1<<'\n';
    int maxSum2 = KadaneAlgo(nums, n);
    cout<<"Maximum subarray Sum using Kadane's Algorithm: "<<maxSum2;
    return 0;
}