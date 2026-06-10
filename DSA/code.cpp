#include <iostream>
using namespace std;

//Starting point of execution

int main(){
    int age = 25;
    char grade = 'A';
    float salary = 50000.50f;
    double totalMarks = 95.75;
    bool isStudent = true;
    //data types in C++ - int, char, float, double, bool
    cout<<sizeof(grade)<<endl; //size of char data type
    cout<<sizeof(salary)<<endl; //size of float data type
    cout<<sizeof(totalMarks)<<endl; //size of double data type
    cout<<sizeof(isStudent)<<endl; //size of bool data type

    //type casting - converting one data type to another
    //explicit type casting - manual conversion by the programmer
    int salaryInt = (int)salary; 
    cout<<salaryInt<<endl;
    //implicit type casting - automatic conversion by the compiler 
    double salaryDouble = salary; //automatic conversion from float to double
    cout<<salaryDouble<<endl;

    //operators - arithmetic, relational, logical, assignment

    //arithmetic operators - +, -, *, /, %
    int a = 10, b = 5;
    cout<<a+b<<endl; //addition
    cout<<a-b<<endl; //subtraction
    cout<<a*b<<endl; //multiplication
    cout<<a/b<<endl; //division
    cout<<a%b<<endl; //modulus

    //relational operators - ==, !=, >, <, >=, <=
    cout<<(a==b)<<endl; //equal to
    cout<<(a!=b)<<endl; //not equal to
    cout<<(a>b)<<endl; //greater than
    cout<<(a<b)<<endl; //less than
    cout<<(a>=b)<<endl; //greater than or equal to
    cout<<(a<=b)<<endl; //less than or equal to

    //logical operators - &&, ||, !
    bool x = true, y = false;
    cout<<(x && y)<<endl; //logical AND
    cout<<(x || y)<<endl; //logical OR
    cout<<(!x)<<endl; //logical NOT

    //assignment operators - =, +=, -=, *=, /=, %=
    int c = 10;
    c += 5; //c = c + 5
    cout<<c<<endl; //15
    c -= 3; //c = c - 3
    cout<<c<<endl; //12
    c *= 2; //c = c * 2
    cout<<c<<endl; //24
    c /= 2; //c = c / 2
    cout<<c<<endl; //12
    c %= 5; //c = c % 5
    cout<<c<<endl; //2

    //unary operators - ++, --
    int d = 5;
    cout<<(++d)<<endl; //pre-increment
    cout<<(d++)<<endl; //post-increment
    cout<<d<<endl; //5
    cout<<(--d)<<endl; //pre-decrement
    cout<<(d--)<<endl; //post-decrement
    cout<<d<<endl; //5

    //bitwise operators - &, |, ^, ~, <<, >>
    int e = 5; //binary: 0101
    int f = 3; //binary: 0011
    cout<<(e & f)<<endl; //bitwise AND
    cout<<(e | f)<<endl; //bitwise OR
    cout<<(e ^ f)<<endl; //bitwise XOR
    cout<<(~e)<<endl; //bitwise NOT
    cout<<(e << 1)<<endl; //left shift
    cout<<(e >> 1)<<endl; //right shift

    return 0;
}

//Boilerplate code - basic structure of a C++ program.   