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

Node* getIS(Node* root){ //IS is the leftmost node in right subtree
    while(!root && !root->left){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){ //O(Height) or O(log n) if balanced binary search tree
    if(!root){
        return NULL;
    }
    if(root->data == key){
        if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        } else{
            Node* is = getIS(root->right);
            root->data = is->data;
            root->right = deleteNode(root->right, is->data);
        }
    }
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    } else{
        root->right = deleteNode(root->right, key);
    }
    return root;
}

void inOrderTraversal(Node* root){ //O(n)
    if(root ==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
    inOrderTraversal(root);
    deleteNode(root, 2);
    cout << '\n';
    inOrderTraversal(root);
    
    return 0;
}