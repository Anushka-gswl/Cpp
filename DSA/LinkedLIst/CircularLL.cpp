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
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        } else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        } else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead(){
        if(head == NULL){
            cout << "List is empty." << '\n';
            return;
        } else if(head == tail){
            delete head;
            head = tail = NULL;
        } else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail(){
        if(head == NULL){
            cout << "List is empty." << '\n';
            return;
        } else if(head == tail){
            delete head;
            head = tail = NULL;
        } else{
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void print(){
        if(head == NULL){
            cout << "List is empty." << '\n';
            return;
        }
        Node* temp = head->next;
        cout << head->data << " => ";
        while(temp != head){
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << temp->data << '\n';
    }
};

int main(){
    List cll;

    cll.insertAtHead(3);
    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.insertAtTail(4);

    cll.print();

    cll.deleteAtHead();

    cll.print();

    cll.deleteAtTail();

    cll.print();
    return 0;
}