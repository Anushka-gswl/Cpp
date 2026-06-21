#include <iostream>
using namespace std;

class Teacher{
public:
    Teacher(){
        cout<<"Hi, I am a teacher";
    }
    string name;
    string dept;
    string subject;
    double salary;
};

int main(){
    Teacher t1;
    return 0;
}