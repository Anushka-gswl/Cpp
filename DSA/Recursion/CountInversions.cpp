#include <iostream>
#include <vector>
using namespace std;

//TC => O(n ^ 2)
//Brute Force Approach
int countInv(vector<int> arr){
    int invCount = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] > arr[j]){
                invCount++;
            }
        }
    }
    return invCount;
}


//TC => O(n * log n), SC => O(n)
//Optimal Approach
int currInvCount(vector<int> &arr, int mid, int st, int end){
    vector<int> temp;
    int invCount = 0;
    int i = st, j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){  //For descending order we use - (arr[i] >= arr[j])
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
            invCount += mid - i + 1;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= end){
        temp.push_back(arr[j++]);
    }
    for(int idx = 0; idx < temp.size(); idx++){
        arr[st + idx] = temp[idx];
    }
    return invCount;
}

int totalInvCount(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = st + (end - st) / 2;
        int leftInvCount = totalInvCount(arr, st, mid);
        int rightInvcount = totalInvCount(arr, mid + 1, end);
        int invCount = currInvCount(arr, mid, st, end);

        return leftInvCount + rightInvcount + invCount;
    }
    return 0;
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = totalInvCount(arr, 0, arr.size() - 1);

    cout << "The number of inversions is: " << ans;
    
    return 0;
}