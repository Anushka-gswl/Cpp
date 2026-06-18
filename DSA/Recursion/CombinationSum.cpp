#include <iostream>
#include <vector>
using namespace std;

void combSum(vector<int>& arr, int i, vector<int> &comb, vector<vector<int>> &ans, int tar){
    int n = arr.size();
    if(tar == 0){
        ans.push_back({comb});
        return;
    }

    if(i == n || tar < 0){
        return;
    }
    
    // inclusion
    comb.push_back(arr[i]);
    combSum(arr, i, comb, ans, tar - arr[i]);

    comb.pop_back(); //Bactracking
    combSum(arr, i + 1, comb, ans, tar);//exclusion
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> comb;
    vector<vector<int>> ans;
    combSum(candidates, 0, comb, ans, target);
    return ans;
}