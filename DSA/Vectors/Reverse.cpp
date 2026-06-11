#include <iostream>
#include <vector>
using namespace std;

void Reverse(  vector<int> &nums, int size){
    int i = 0, j = size-1;
    while( i < j){
        swap(nums[i], nums[j]);
        i++, j--;
    }
    return;
}

int main(){
    cout<<"Enter size of vector: ";
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements: ";
    for(int i =0 ; i < n; i++){
        cin>>nums[i];
    }
    Reverse(nums, n);
    
    for( int i =0; i < n; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}