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
    int singleDigitSum(int n, int k){
        int sum = sumOfDigits(n) * k;
        while(sum > 9){
            sum = sumOfDigits(sum);
        }
        return sum;
    }
};

int main(){
    Solution sol;

    int n, k;
    cin >> n;
    cin >> k;

    cout << sol.singleDigitSum(n, k);
    return 0;
}