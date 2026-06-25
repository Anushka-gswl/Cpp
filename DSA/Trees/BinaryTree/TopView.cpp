#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void topView(Node* root){ //O(n * log n)
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while(q.size()){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){ //O(log n)
            m[currHD] = curr->data;
        }
        if(curr->left){
            q.push({curr->left, currHD - 1});
        }
        if(curr->right){
            q.push({curr->right, currHD + 1});
        }
    }

    for(auto a : m){
        cout << a.second << " ";
    }

}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    topView(root);

    return 0;
}