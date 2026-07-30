#include <iostream>
#include <vector>
using namespace std;

class Solution{
public: 
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    void primeMultipliedSeries(int n){
        int numPrimes = 2*(n/3) + n%3;
        vector<int> requiredPrimes;
        int i = 2;
        while(requiredPrimes.size() < numPrimes){
            if(isPrime(i)){
                requiredPrimes.push_back(i);
            }
            i++;
        }
        int done = 0;
        for(int i = 0; i < requiredPrimes.size(); i+=2){
            cout << requiredPrimes[i] << " ";
            done++;
            if(done < n){
                cout << requiredPrimes[i+1] << " ";
            }
            done++;
            if(done < n){
                cout << requiredPrimes[i] * requiredPrimes[i+1] << " ";
            }
            done++;
        }
    }
};

int main(){
    Solution s;

    int n;
    cout <<"Enter n: ";
    cin >> n;
    
    s.primeMultipliedSeries(n);
    return 0;
}