#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool isPossible( vector<int> arr, int n, int m, int minAllowedDist){ //TC => O(n)
    int cows = 1, lastStallPos = arr[0];
    for(int i = 1; i < n; i++){
        if( arr[i] - lastStallPos >= minAllowedDist){
            cows++;
            lastStallPos = arr[i];
        }
        if( cows == m){
            return true;
        }
    }
    return false; 
}

int maxDist(vector<int> &arr, int n, int m){
    sort( arr.begin(), arr.end()); //O(NlogN)
    int maxVal = INT_MIN, minVal = INT_MAX;
    for(int i = 0; i < n; i++){
        maxVal = max(arr[i], maxVal);
        minVal = min(arr[i], minVal);
    }
    int st = 1, end = maxVal - minVal, ans = -1;
    while( st <= end){   //O(log(Range) * N)
        int mid = st + ( end - st) / 2;
        if( isPossible(arr, n, m, mid)){
            ans = mid;
            st = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout<<"Enter number of stalls: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter position of each stall: ";
    for( int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter number of cows: ";
    cin>>m;

    int ans = maxDist(arr,n,m);
    cout<<"Maximum minimum distance between the cows is: "<<ans;
    return 0;
}