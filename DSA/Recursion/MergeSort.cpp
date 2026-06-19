#include <iostream>
#include <vector>
using namespace std;

//TC => O(n * log n), SC => O(n)

void merge(vector<int> &arr, int mid, int st, int end){
    vector<int> temp;
    int i = st, j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){  //For descending order we use - (arr[i] >= arr[j])
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
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
}

void mergeSort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, mid, st, end);
    }
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

    mergeSort(arr, 0, n - 1);

    cout << "The sorted array is:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}