#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char>& chars) { //O(n)
    int idx = 0;
    for(int i = 0; i < chars.size(); i++){
        char ch = chars[i];
        int count = 0;
        while( i < chars.size() && chars[i] == ch){
            count++;
            i++;
        }
        if(count == 1){
            chars[idx++] = ch;
        } else{
            chars[idx++] = ch;
            string num = to_string(count);
            for( char dig : num){
                chars[idx++] = dig;
            }
        }
        i--;
    }
    return idx; //or we can - chars.resize(idx); return chars.size();
        
}