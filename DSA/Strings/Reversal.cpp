#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //For character array
    vector<char> str = {'h', 'e', 'l', 'l', 'o', '\0'};
    int st = 0, end = str.size() - 1;
    while( st < end){
        swap(str[st++], str[end--]);
    }
    for( char s : str){
        cout << s << ' ';
    }
    cout << '\n';

    //For string
    string str1 = "Anushka";
    reverse(str1.begin(), str1.end());
    cout << str1 <<'\n';
    return 0;
}