#include <iostream>
#include <vector>
#include <queue>
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

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void kLevel(Node* root, int k){ //O(n)
    if(!root){
        return;
    }
    if(k == 1){
        cout << root->data << " ";
        return;
    }
    kLevel(root->left, k - 1);
    kLevel(root->right, k - 1);
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    kLevel(root, 3);

    return 0;
}