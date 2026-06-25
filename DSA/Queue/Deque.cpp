#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> q;
    q.push_front(1);
    q.push_front(2);
    q.push_back(3);
    q.push_back(4);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }
    
    cout << '\n';
    
    q.push_front(1);
    q.push_front(2);
    q.push_back(3);
    q.push_back(4);

    while(!q.empty()){
        cout << q.back() << " ";
        q.pop_back();
    }
    return 0;
}