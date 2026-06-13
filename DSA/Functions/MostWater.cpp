#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
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

int main(){
    int n;
    cout<<"Enter size of height array: ";
    cin>>n;
    vector<int> height(n);
    cout<<"Enter values of height array:\n";
    for(int i = 0; i < n; i++){
        cin>>height[i];
    }
    int mw = maxArea(height);
    cout<<"Maximum nater that can be stored is: "<<mw;
    return 0;
}