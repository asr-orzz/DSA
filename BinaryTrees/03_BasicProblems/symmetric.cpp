#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Symmetric = tree is a mirror of itself
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

bool mirror(Node* a,Node* b){
    if(!a && !b) return true;
    if(!a || !b) return false;
    if(a->val!=b->val) return false;
    return mirror(a->left,b->right) && mirror(a->right,b->left);
}

bool symmetric(Node* root){
    if(!root) return true;
    return mirror(root->left,root->right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then symmetric(root)

    return 0;
}
