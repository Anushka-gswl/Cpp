#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val){
        data = val;
        next = prev = child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {  //TC => O(n)
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                //flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                //find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }

                //attach tail with next ptr
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << '\n';
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    n6->prev = n5;

    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    n8->prev = n7;
    n9->prev = n8;
    n10->prev = n9;

    n11->next = n12;

    n12->prev = n11;

    n3->child = n7;
    n8->child = n11;

    Solution obj;

    Node* head = obj.flatten(n1);

    cout << "Flattened List: ";
    printList(head);

    return 0;
}