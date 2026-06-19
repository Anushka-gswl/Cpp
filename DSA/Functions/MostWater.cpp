#include <iostream>
#include <vector>
using namespace std;

//Brute Force - gives TLE on leetcode, TC => O(n^2)
int maxArea1(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;
    for( int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = j - i;
            int h = min( height [i], height [j]);
            int currWater = w * h;
            maxWater = max (maxWater, currWater);
        }
    }
    return maxWater;
}

//Optimized Approach - TC => O(n)
int maxArea(vector<int>& height) {
    int maxWater = 0;
    int l = 0, r = height.size() - 1;
    while ( l < r){
        int w = r - l;
        int ht = min ( height[l], height[r]);
        int currWater = w * ht;
        maxWater = max( maxWater, currWater);

        if(height[l] < height[r]){
            l++;
        } else {
            r--;
        }
    }
    return maxWater;
}

int main(){
    int n;
    cout<<"Enter size of height array: ";
    cin>>n;
    vector<int> height(n);
    cout<<"Enter values of height array:\n";
    for(int i = 0; i < n; i++){
        cin>>height[i];
    }
    int mw = maxArea1(height);
    cout<<"Maximum water that can be stored is: "<<mw;
    return 0;
}