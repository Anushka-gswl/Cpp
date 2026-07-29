#include <iostream>
using namespace std;

class Solution{
public:
    int sumOfDigits(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    bool isPrime(int n){
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int evenSumPrimes(int start, int end) {
        int count = 0;
        for(int i = start; i <= end; i++){
            if(isPrime(i) && sumOfDigits(i) % 2 == 0){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;

    int start, end;
    cin >> start >> end;

    cout << sol.evenSumPrimes(start, end);
    return 0;
}