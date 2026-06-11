#include <iostream>
using namespace std;

int Sum(int arr[], int size){
    int sum = 0; 
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int Product(int arr[], int size){
    int pr = 1; 
    for (int i = 0; i < size; i++){
        pr *= arr[i];
    }
    return pr;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5};
    int sum = Sum(arr,5);
    int prod = Product(arr,5);
    cout<<"Sum of all array elements is: "<<sum<<'\n';
    cout<<"Product of all array elements is: "<<prod<<'\n';
    return 0;
}