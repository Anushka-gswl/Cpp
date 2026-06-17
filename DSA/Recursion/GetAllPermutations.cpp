#include <iostream>
#include <vector>
using namespace std;

//TC => O(n * n!), SC => O(n!)
void getAllPermutations(vector<int> &nums, int idx, vector<vector<int>> &allPermutations){
    if(idx == nums.size()){
        allPermutations.push_back({nums});
        return;
    }

    for(int i = idx; i < nums.size(); i++){
        swap(nums[idx], nums[i]);
        getAllPermutations(nums, idx + 1, allPermutations);
        swap(nums[idx], nums[i]); //Backtracking
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> allPermutations;

    getAllPermutations(nums, 0, allPermutations);

    return allPermutations;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans = permute(arr);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}