#include <iostream>
#include <vector>
using namespace std;

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