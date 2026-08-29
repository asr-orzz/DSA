#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// LCA in a general binary tree (no BST property)
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* lca(Node* node,int p,int q){
    if(!node) return NULL;
    if(node->val==p || node->val==q) return node;

    Node* l = lca(node->left,p,q);
    Node* r = lca(node->right,p,q);

    if(l && r) return node;   // p and q split here
    return l ? l : r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then lca(root,p,q)

    return 0;
}
