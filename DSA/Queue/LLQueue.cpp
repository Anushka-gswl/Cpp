#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = tail = NULL;
    }

    void push(int val){ //O(1)
        Node* newNode = new Node(val);
        if(empty()){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){ //O(1)
        if(empty()){
            cout << "Queue is empty." << '\n';
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){ //O(1)
        if(empty()){
            return -1;
        }
        return head->data;
    }

    bool empty(){ //O(1)
        return head == NULL;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();

    q.pop();
    q.display();

    cout << q.front() << '\n';
    cout << (q.empty() ? "Queue is empty." : "Queue is not empty.") << '\n';

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}