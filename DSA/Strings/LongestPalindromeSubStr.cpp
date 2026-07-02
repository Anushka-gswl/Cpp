#include <iostream>
#include <string>
using namespace std;

//Brute-Force Approach - TC => O(n^3), SC => O(1)
//Sliding Window Approach
class Solution1 {
public:
    bool isPalindrome(int st, int end, string& s){
        while(st < end){
            if(s[st++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.length() == 1){
            return s;
        }
        
        int windL = s.length();

        while(windL>=1){
            int i = 0;
            while(i + windL <= s.length()){
                if(isPalindrome(i, i+windL-1, s)){
                    return s.substr(i, windL);
                }
                i++;
            }
            windL--;
        }
        return "";
    }
};

//Optimized Approach - TC => O(n^2), SC => O(1)
//Expand around center approach
class Solution2 {
public:
    bool isPalindrome(int st, int end, string& s){
        while(st < end){
            if(s[st++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.length() <= 1){
            return s;
        }
        
        int st = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++){
            //odd-length string
            int l = i, r = i; 
            while(l>=0 && r<s.length() && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    st = l;
                    maxLen = r - l + 1;
                }
                l--, r++;
            }

            //even-length string
            l = i, r = i+1;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    st = l;
                    maxLen = r - l + 1;
                }
                l--, r++;
            }
        }

        return s.substr(st, maxLen);
    }
};