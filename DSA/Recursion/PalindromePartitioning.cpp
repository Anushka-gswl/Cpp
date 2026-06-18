#include <iostream>
#include <vector>
#include<string>
using namespace std;

//Tc => O(n * 2 ^ n)

bool isPalindrome(string str){ //or we can simply use str2 = str; reverse(str.begin(), str.end()); and then check if str == str2
    int st = 0, end = str.length() - 1;
    while(st < end){
        if(str[st++] != str[end--]){
            return false;
        }
    }
    return true;
}

    void getAllPartitions(string s, vector<string> &partition, vector<vector<string>> &ans){
    if(s.length() == 0){
        ans.push_back(partition);
        return;
    }
    for(int i = 0; i < s.size(); i++){
        string part = s.substr(0, i + 1);
        if(isPalindrome(part)){
            partition.push_back(part);
            getAllPartitions(s.substr(i + 1), partition, ans);

            partition.pop_back();//backtracking
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partition;

    getAllPartitions(s, partition, ans);
    return ans;
}