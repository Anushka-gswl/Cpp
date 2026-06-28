#include <iostream>
#include <vector>
using namespace std;

//O(m + n)

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

Node* buildBalancedBSTFromSorted(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end - st) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildBalancedBSTFromSorted(arr, st, mid - 1);
    root->right = buildBalancedBSTFromSorted(arr, mid + 1, end);
    return root;
}

void inorder(Node* root, vector<int>& arr){
    if(!root){
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

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

Node* mergeBST(Node* root1, Node* root2){
    vector<int> tree1;
    vector<int> tree2;
    inorder(root1, tree1);
    inorder(root2, tree2);
    
    vector<int> ans;
    int i =0, j = 0;
    while(i < tree1.size() && j < tree2.size()){
        if(tree1[i] < tree2[j]){
            ans.push_back(tree1[i++]);
        } else{
            ans.push_back(tree2[j++]);
        }
    }
    while(i < tree1.size()){
        ans.push_back(tree1[i++]);
    }
    while(j < tree2.size()){
        ans.push_back(tree2[j++]);
    }
    
    Node* root = buildBalancedBSTFromSorted(ans, 0, ans.size() - 1);

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
    vector<int> arr1 = {3, 7, 1, 4, 8, 6};
    vector<int> arr2 = {2, 5, 9, 11};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    inOrderTraversal(root1);
    cout << '\n';
    inOrderTraversal(root2);
    cout << '\n';

    Node* root = mergeBST(root1, root2);

    inOrderTraversal(root);
    return 0;
}