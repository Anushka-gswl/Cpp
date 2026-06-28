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

void inOrderTraversal(Node* root){ //O(n)
    if(root ==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

vector<int> morrisInorder(Node* root){ //O(n)
    vector<int> ans;
    Node* curr = root;
    
    while(curr){
        if(!curr->left){
            ans.push_back(curr->data);
            curr = curr->right;
        } else{
            //find the inorder predecessor
            Node* ip = curr->left;
            if(ip->right && ip->right != curr){
                ip = ip->right;
            }

            if(!ip->right){
                ip->right = curr; //create thread
                curr = curr->left;
            } else{
                ip->right = NULL; //destroy thread
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    inOrderTraversal(root);
    
    cout << '\n';
    
    vector<int> ans = morrisInorder(root);
    for(int a : ans){
        cout << a << " ";
    }

    return 0;
}