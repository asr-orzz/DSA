#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Validate BST — each node must lie in (low, high)
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

bool valid(Node* node,ll low,ll high){
    if(!node) return true;
    if(node->val<=low || node->val>=high) return false;
    return valid(node->left,low,node->val) && valid(node->right,node->val,high);
}

bool isBST(Node* root){
    return valid(root,LLONG_MIN,LLONG_MAX);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then isBST(root)

    return 0;
}
