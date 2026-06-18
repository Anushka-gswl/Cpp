#include <iostream>
#include <vector>
#include<string>
using namespace std;

//TC => O(4 ^ (n ^ 2))

void helper(vector<vector<string>> &grid, int r, int c, string path, vector<string> &ans){
    int n = grid.size();
    if(r < 0 || c < 0 || r >= n || c>= n || grid[r][c] != "1"){
        return;
    }

    if(r == n -1 && c == n - 1){
        ans.push_back(path);
        return;
    }
    
    grid[r][c] = "-1";

    helper(grid, r + 1, c, path + "D", ans);
    helper(grid, r , c + 1, path + "R", ans);
    helper(grid, r - 1, c, path + "U", ans);
    helper(grid, r, c - 1, path + "L", ans);

    grid[r][c] = "1";
}

vector<string> searchPaths(vector<vector<string>> &grid){
    vector<string> ans;
    string path = "";
    helper(grid, 0, 0, path, ans);

    return ans;
}

int main(){
    vector<vector<string>> grid = {{"1", "0", "0", "0"}, {"1", "1", "0", "1"}, {"1", "1", "0", "0"}, {"0", "1", "1", "1"}};
    vector<vector<string>> grid1 = {
    {"1","0","0","0"},
    {"1","1","0","1"},
    {"1","1","0","0"},
    {"1","1","1","1"}};
    vector<string> ans = searchPaths(grid1);
    for(string a : ans){
        cout << a << '\n';
    }
    return 0;
}