#include <iostream>
#include <vector>
using namespace std;

//Average / Practical TC => O(n * log n), SC => O(1), Worst Case TC => O(n ^ 2)

int partition(vector<int> &arr, int st, int end){
    int idx = st - 1, pivot = arr[end];
    for(int j = st; j < end; j++){
        if(arr[j] <= pivot){ //For descending order we use - (arr[j] >= pivot)
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end){
    if(st < end){
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);
        quickSort(arr, pivIdx + 1, end);
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

    quickSort(arr, 0, n - 1);

    cout << "The sorted array is:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}