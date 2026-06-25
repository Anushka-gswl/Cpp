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

bool isSame(Node* p, Node* q){
    if(!p || !q){
        return p == q;
    }
    return isSame(p->left, q->left) && isSame(p->right, q->right) && p->data == q->data;
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root1 = buildTree(preOrder);
    idx = -1;
    vector<int> preOrder2 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, 6, -1, -1};
    Node* root2 = buildTree(preOrder2);

    cout << isSame(root1, root2);

    return 0;
}