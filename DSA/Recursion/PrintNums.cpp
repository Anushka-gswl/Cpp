#include <iostream>
#include<vector>
using namespace std;

void printN(int n){
    if(n==1){
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    printN(n - 1);
}

int main(){
    int n;
    cin>>n;
    printN(n);
    return 0;
}