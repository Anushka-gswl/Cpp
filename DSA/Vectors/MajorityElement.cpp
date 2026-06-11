#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Majority element is the one that occurs more than floor(n/2) times in the array

//Brute Force Approach
int MajorityElement( vector<int> nums, int n){
    for( int val : nums){
        int freq = 0;
        for( int el : nums){
            if( val == el){
                freq++;
            }
        }
        if( freq > n/2){
            return val;
        }
    }
    return -1;
}

//Optimized Solution
int MajElement( vector<int> nums, int n){

    sort( nums.begin(), nums.end());

    int freq = 1, ans = nums[0];
    for( int i =1; i < n; i++){
        if( nums[i] == nums[i-1]){
            freq++;
        } else{
            freq = 1;
            ans = nums [i];
        }
        if( freq > n/2){
            return ans;
        }
    }
    return ans;
}

//Moore's Voting Algorithm - Most optimal
int MElement(vector<int> nums, int n){
    int freq = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if( freq == 0){
            ans = nums[i];
        }
        if( nums[i] == ans){
            freq++;
        } else{
            freq--;
        }
    }
    //case when there is no majority element
    int count;
    for(int i = 0; i < n; i++){
        if(nums[i] == ans){
            count++;
        }
    }
    if( count > n/2){
        return ans;
    } else{
        return -1;
    }
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
    int el1 = MajorityElement(nums, n);
    cout<<"Majority Element is: "<<el1<<'\n';
    int el2 = MajElement(nums, n);
    cout<<"Majority Element is: "<<el2<<'\n';
    int el3 = MElement(nums, n);
    cout<<"Majority Element is: "<<el3<<'\n';
    return 0;
}