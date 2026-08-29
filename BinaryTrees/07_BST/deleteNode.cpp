#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(H)
// BST delete: 0/1 child -> splice; 2 children -> replace with inorder successor
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* findMin(Node* node){
    while(node->left) node = node->left;
    return node;
}

Node* deleteNode(Node* node,int key){
    if(!node) return NULL;

    if(key<node->val) node->left = deleteNode(node->left,key);
    else if(key>node->val) node->right = deleteNode(node->right,key);
    else{
        if(!node->left) return node->right;
        if(!node->right) return node->left;

        Node* succ = findMin(node->right); // smallest in right subtree
        node->val = succ->val;
        node->right = deleteNode(node->right,succ->val);
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build BST root, then root = deleteNode(root,key)

    return 0;
}
