#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(H)
// LCA in BST — walk down using ordering
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* lca(Node* node,int p,int q){
    while(node){
        if(p<node->val && q<node->val) node = node->left;
        else if(p>node->val && q>node->val) node = node->right;
        else return node; // split point
    }
    return NULL;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build BST root, then lca(root,p,q)

    return 0;
}
