#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    int ans = 0;
    vector<bool> isPrime(n+1, true);
    for(int i = 2; i < n; i++){
        if(isPrime[i]){
            ans++;
        }
        for(int j = i * 2; j < n; j +=i){
            isPrime[j] = false;
        }
    }
    return ans;
}