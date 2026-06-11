#include <iostream>
#include <vector>
using namespace std;

int main(){
    cout<<"Enter size of vector: ";
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements: ";
    for(int i =0 ; i < n; i++){
        cin>>nums[i];
    }

    for(int st = 0; st < n; st++){
        for( int end = st; end < n; end++){
            for(int i = st; i <= end; i++){
                cout<<nums[i];
            }
            cout<<" ";
        }
        cout<<'\n';
    }
    return 0;
}