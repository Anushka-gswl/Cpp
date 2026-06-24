/* 
Celebrity Problem

Given a 2D array arr of size n × n, where:

arr[i][j] = 1 means person i knows person j.
arr[i][j] = 0 means person i does not know person j.

The task is to find the celebrity.

A celebrity is a person who:

Is known by everyone else.
Does not know anyone.

Return the index of the celebrity if one exists; otherwise, return -1.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//TC => O(n), SC => O(n)

int getCelebrity(vector<vector<int>> arr){
    int n = arr.size();
    stack<int> s;

    for(int i = 0; i< n; i++){
        s.push(i);
    }

    while(s.size() > 1){
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if(arr[i][j] == 0){
            s.push(i);
        } else{
            s.push(j);
        }
    }

    int celeb = s.top();

    for(int i = 0; i < n; i++){
        if((i != celeb) && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){
            return -1;
        }
    }

    return celeb;
}

int main(){
    vector<vector<int>> arr ={{0, 1, 0}, {0, 0, 1}, {0, 1, 0}};

    int ans = getCelebrity(arr);

    cout << "The celebrity is: " << ans;

    return 0;
}
