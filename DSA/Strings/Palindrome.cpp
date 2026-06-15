#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome( string str1){
    string str2 = str1;
    
    reverse(str1.begin(), str1.end());

    if( str1 == str2){
        return true;
    }else{
        return false;
    }
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