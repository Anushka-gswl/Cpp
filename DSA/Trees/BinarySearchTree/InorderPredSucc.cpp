#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* inorderPred(Node* root){
    Node* ans;
    while(root){
        ans = root;
        root = root->right;
    }
    return ans;
}

Node* inorderSucc(Node* root){
    Node* ans;
    while(root){
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredSucc(Node* root, int key){ //TC => O(h), SC => O(1)
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        } else if(key > curr->data){
            pred = curr;
            curr = curr->right;  
        } else{
            if(curr->left){
                pred = inorderPred(curr->left);
            }
            if(curr->right){
                succ = inorderSucc(curr->right);
            }
            break;
        }
    } 
    return {pred->data, succ->data};
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 5;
    vector<int> ans = getPredSucc(root, key);
    cout << "Predecessor: " << ans[0] << '\n';
    cout << "Successor: " << ans[1];
    return 0;
}