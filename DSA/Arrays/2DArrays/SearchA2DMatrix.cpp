#include <iostream>
#include <vector>
using namespace std;

//Brute force approach - Linear search on matrix - TC => O(m * n)

//Optimized Approach - TC => O(log(m + log n))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i = 0;
    while( i < matrix.size()){
        if(matrix[i][matrix[i].size() - 1] < target){
            i++;
        }
        int st = 0, end = matrix[i].size() - 1;
        while(st < end){
            int mid = st + ( end - st) / 2;
            if( matrix[i][mid] == target){
                return true;
            } else if( matrix[i][mid] > target){
                st = mid + 1;
            } else{
                end = mid - 1;
            }
        }
    }
    return false;
}

//Optimal Approach - TC => O( log (m * n))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int stR = 0, endR = m - 1;
    while(stR <= endR){
        int midR = stR + (endR - stR) / 2;
        if( target >= matrix[midR][0] && target <= matrix[midR][n - 1]){
            int stC = 0, endC = n - 1;
            while(stC <= endC){
                int midC = stC + ( endC - stC) / 2;
                if( matrix[midR][midC] == target){
                    return true;
                } else if( target > matrix[midR][midC]){
                    stC = midC + 1;
                } else{
                    endC = midC - 1;
                }
            }
            return false;
        } else if( target > matrix[midR][n - 1]){
            stR = midR + 1;
        } else{
            endR = midR - 1;
        }
    }
    return false;
}

//Or even cleaner, find the row first, then perform a separate binary search on that row