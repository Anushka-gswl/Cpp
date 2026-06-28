#include <iostream>
#include <climits>
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

class Info{
public:
    int min, max, size;

    Info(int mi, int ma, int sz){
        min = mi;
        max = ma;
        size = sz;
    }
};

Info helper(Node* root){
    if(!root){
        return Info(INT_MAX, INT_MIN, 0);
    }
    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min){
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSize = left.size + right.size + 1;

        return Info(currMin, currMax, currSize);
    }
    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBSTinBT(Node* root){ //O(n)
    Info info = helper(root);
    return info.size;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->right = new Node(50);

    cout << largestBSTinBT(root);
    return 0;
}