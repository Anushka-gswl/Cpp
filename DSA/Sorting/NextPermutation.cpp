#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &nums, int i, int j){
    while( i <= j){
        swap(nums[i++], nums[j--]);
    }
}

// we can simply use - next_permutation(nums.begin(), nums.end()) 
void nextPermutation(vector<int>& nums) {  //TC => O(n), SC => O(1)
    int n = nums.size();
    int piv = -1;
    for( int i = n - 2; i >= 0; i--){
        if( nums[i] < nums[i + 1]){
            piv = i;
            break;
        }
    }
    if(piv == -1){
        reverse(nums, 0, n-1); //we can also use reverse(nums.begin(), nums.end())
        return;
    }
    for( int i = n - 1; i >= 0; i--){
        if( nums[i] > nums[piv]){
            swap( nums[i], nums[piv]);
            break;
        }
    }
    reverse(nums, piv + 1, n-1); //we can also use reverse(nums.begin() + piv + 1, nums.end())
}

void printArray(vector<int> arr){
    for ( int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    vector<int> arr = {4,4,6,2,8,9,3,3};
    nextPermutation(arr);
    printArray(arr);
    return 0;
}