#include <iostream>
using namespace std;

int main(){
    char ch;
    //using character literals to check if the input character is uppercase or lowercase
    cout<<"Enter an alphabet character: ";
    cin>>ch;
    if (ch>='a' && ch<='z') {
        cout<<"Lowercase Character"<<"\n";
    } else if (ch>='A' && ch<='Z') {
        cout<<"Uppercase Character"<<"\n";
    } else {
        cout<<"Not an alphabet"<<"\n";
    }

    //using numeric values to check if the input character is uppercase or lowercase
    cout<<"Enter an alphabet character: ";
    cin>>ch;
    if (ch>=97 && ch<=122) {
        cout<<"Lowercase Character"<<"\n";
    } else if (ch>=65 && ch<=90) {
        cout<<"Uppercase Character"<<"\n";
    } else {
        cout<<"Not an alphabet"<<"\n";
    }
    return 0;
}