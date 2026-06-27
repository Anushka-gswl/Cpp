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

Node* insert(Node* root, int val){
    if(!root){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for(int a : arr){
        root = insert(root, a);
    }
    return root;
}

bool search(Node* root, int key){ //O(Height) or O(log n) if balanced binary search tree
    if(!root){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left, key);
    } else{
        return search(root->right, key);
    }
}

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);

    cout << (search(root, 5) ? "True" : "False");
    return 0;
}