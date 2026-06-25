#include <iostream>
#include <deque>
using namespace std;

class CircularQueue{
    int* arr;
    int currSize, capacity;
    int f, r;

public:
    CircularQueue(int size){
        capacity = size;
        currSize = 0;
        arr = new int[capacity];
        f = 0, r = -1;
    }

    void push(int val){
        if(currSize == capacity){
            cout << "Queue is full." << '\n';
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = val;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout << "Queue is empty." << '\n';
            return;
        }   
        f = (f + 1) % capacity;
        currSize--;
    }

    int front(){
        if(empty()){
            return -1;
        }
        return arr[f];
;   }

    bool empty(){
        return currSize == 0;
    }

    void printArr(){
        for(int i = 0; i < capacity; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
};

int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);

    cq.printArr();
    while(!cq.empty()){
        cout << cq.front() << " ";
        cq.pop();
    }

    return 0;
}