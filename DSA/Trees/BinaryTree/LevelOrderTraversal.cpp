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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()){
        Node* curr = q.front();
        q.pop();
        if(!curr){ //for line-wise level order traversal
            if(!q.empty()){
                cout << '\n';
                q.push(NULL);
                continue;
            } else{
                break;
            }
        }
        cout << curr->data << " ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }

}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    levelOrderTraversal(root);

    return 0;
}