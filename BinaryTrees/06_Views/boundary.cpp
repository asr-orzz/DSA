#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Boundary traversal (anti-clockwise): root + left boundary + leaves + right boundary
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

bool isLeaf(Node* node){
    return !node->left && !node->right;
}

void leftBoundary(Node* node,vector<int> &res){
    Node* cur = node->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->val);
        cur = cur->left ? cur->left : cur->right;
    }
}

void leaves(Node* node,vector<int> &res){
    if(!node) return;
    if(isLeaf(node)){
        res.push_back(node->val);
        return;
    }
    leaves(node->left,res);
    leaves(node->right,res);
}

void rightBoundary(Node* node,vector<int> &res){
    Node* cur = node->right;
    vector<int> tmp;
    while(cur){
        if(!isLeaf(cur)) tmp.push_back(cur->val);
        cur = cur->right ? cur->right : cur->left;
    }
    reverse(tmp.begin(),tmp.end()); // bottom-up
    for(int v : tmp) res.push_back(v);
}

vector<int> boundary(Node* root){
    vector<int> res;
    if(!root) return res;

    if(!isLeaf(root)) res.push_back(root->val);
    leftBoundary(root,res);
    leaves(root,res);
    rightBoundary(root,res);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then boundary(root)

    return 0;
}
