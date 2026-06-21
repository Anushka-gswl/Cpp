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

class List{
private:
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);//dynamic
        //Static - Node newNode(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        } else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is empty" << '\n';
            return;
        }
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    void insert(int val, int pos){
        if(pos < 0){
            cout << "Enter a valid positive value for position." << '\n';
        }
        if(pos == 0){
            return push_front(val);
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        int prevPos = 0; //indexing starts from 0
        while(prevPos < pos - 1){
            if(temp == NULL){
                cout << "Invalid position." << '\n';
            }
            temp = temp -> next;
            prevPos++;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void pop_back(){
        if(head == NULL){
            cout << "LL is empty" << '\n';
            return;
        }
        Node* temp = head;
        while(temp -> next != tail){ // or we can use (temp->next->next != NULL)
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    void show(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << '\n';
    }

    int search(int key){
        if(head == NULL){
            cout << "Linked List is empty." << '\n';
        }
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp -> data == key){
                return idx;
            }
            temp = temp -> next;
            idx++;
        }
        return -1;
    }

};

int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(0);
    ll.pop_front();
    ll.pop_back();
    ll.insert(8,2);

    ll.show();

    cout << ll.search(5);

    return 0;
}