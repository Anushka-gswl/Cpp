#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime){
    int painter = 1, time = 0;
    for(int i = 0; i < n; i++){
        if( arr[i] > maxAllowedTime){
            return false;
        }
        if( arr[i] + time <= maxAllowedTime){
            time += arr[i];
        } else{
            painter++;
            time = arr[i];
        }
    }
    return painter > m ? false : true;
}

int minTime(vector<int> &arr, int n, int m){
    int ans = -1;
    int maxLen = INT_MIN;
    int sum = 0;
    for( int i = 0; i < n; i++){
        maxLen = max( arr[i], maxLen);
        sum += arr[i];
    }
    
    int st = maxLen, end = sum;
    while( st <= end){
        int mid = st + ( end - st) / 2;
        if( isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        } else{
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout<<"Enter number of boards: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter length of each board: ";
    for( int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter number of painters: ";
    cin>>m;

    int ans = minTime(arr,n,m);
    cout<<"Minimum time to paint all boards is: "<<ans;
    return 0;
}