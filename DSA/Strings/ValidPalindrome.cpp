#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAlphaNum(char a){ // we can simply use the c++ function - isalnum(a)
    if( (a >= '0' && a <= '9') || (tolower(a) >= 'a' && tolower(a) <= 'z')){
        return true;
    } else{
        return false;
    }
}
bool isPalindrome(string s) {
    int st = 0, end = s.length() - 1;
    while( st <= end){
        if(!isAlphaNum(s[st])){
            st++;
            continue;
        }
        if(!isAlphaNum(s[end])){
            end--;
            continue;
        }
        if( tolower(s[st]) != tolower(s[end])){
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main(){
    string str1;
    cout << "Enter a string: ";
    cin >> str1;

    if( isPalindrome(str1)){
        cout << "Palindrome";
    }else{
        cout << "Not Palindrome";
    }
    return 0;
}