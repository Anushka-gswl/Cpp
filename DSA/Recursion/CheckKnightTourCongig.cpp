#include <iostream>
#include <vector>
using namespace std;

//RECURSION AND SIMULATION
//Method 1 - TC => O(n ^ 4), SC => O(n ^ 2)
bool isValid(int currR, int currC, int nextR, int nextC){
    if((nextR == currR - 1 && nextC == currC - 2) 
    || (nextR == currR - 2 && nextC == currC - 1) 
    || (nextR == currR - 2 && nextC == currC + 1) 
    || (nextR == currR - 1 && nextC == currC + 2) 
    || (nextR == currR + 1 && nextC == currC + 2) 
    || (nextR == currR + 2 && nextC == currC + 1) 
    || (nextR == currR + 2 && nextC == currC - 1) 
    || (nextR == currR + 1 && nextC == currC - 2)){
        return true;
    }
    return false;
}

bool validMove(vector<vector<int>>& grid, int move, int currR, int currC){
    int n = grid.size();
    if(move == (n * n) - 1){
        return true;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == move + 1 && move < n * n){
                if(!isValid(currR, currC, i, j)){
                    return false;
                } else{
                    return validMove(grid, move + 1, i, j);
                }
            }
        }
    }
    return true;
}

bool checkValidGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] != 0){
        return false;
    }
    return validMove(grid, 0, 0, 0);
}

//RECURSION AND BACKTRACKING
//Method 2 - TC => O(8 ^ (n ^ 2)), SC => O(n ^ 2)
bool isValid(vector<vector<int>> &grid, int r, int c, int expMoveVal){
    int n = grid.size();
    if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expMoveVal){
        return false;
    }
    if(expMoveVal == (n * n - 1)){
        return true;
    }

    int ans1 = isValid(grid, r - 2, c - 1, expMoveVal + 1);
    int ans2 = isValid(grid, r - 1, c - 2, expMoveVal + 1);
    int ans3 = isValid(grid, r + 2, c - 1, expMoveVal + 1);
    int ans4 = isValid(grid, r + 1, c - 2, expMoveVal + 1);
    int ans5 = isValid(grid, r - 2, c + 1, expMoveVal + 1);
    int ans6 = isValid(grid, r - 1, c + 2, expMoveVal + 1);
    int ans7 = isValid(grid, r + 2, c + 1, expMoveVal + 1);
    int ans8 = isValid(grid, r + 1, c + 2, expMoveVal + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid(vector<vector<int>>& grid) {
    return isValid(grid, 0, 0, 0);
}
