#include <iostream>
#include <vector>
using namespace std;

//TC => O(n * 2^n)
void printSubsets(vector<int> arr, vector<int> &ans, int i){
    if(i == arr.size()){
        for(int a : ans){
            cout << a << " ";
        }
        cout << '\n';
        return;
    }

    //include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    //bactrack
    ans.pop_back();

    //exclude
    printSubsets(arr, ans, i + 1);
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int>ans;

    printSubsets(arr, ans, 0);

    return 0;
}