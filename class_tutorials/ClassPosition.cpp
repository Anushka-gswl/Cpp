#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

class Solution{
public:
    void classPosition(int n, vector<int>&A){
        set<int, greater<int>> B(A.begin(), A.end());

        unordered_map<int, pair<int, int>> mp;
        for(int a : A){
            mp[a].first++;
        }
        int rank = 1;
        for(int a : B){
            mp[a].second = rank;
            rank += mp[a].first;
        }

        for(int a : A){
            cout << mp[a].second << " ";
        }
    }
};

int main(){
    Solution s;

    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    s.classPosition(n, A);

    return 0;
}