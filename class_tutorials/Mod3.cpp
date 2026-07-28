#include <iostream>
using namespace std;

class Solution{
public:
    int mod3(int start, int end) {
        int count = 0;
        for(int i = start; i <= end; i++){
            int num = i;
            int sum = 0;
            while(num > 0){
                int digit = num % 10;
                sum += digit;
                num /= 10; 
            }
            if(sum % 3 == 0 && sum % 2 == 0){
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

    cout << sol.mod3(start, end);
    return 0;
}