#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Distance between two nodes = depth(p)+depth(q)-2*depth(lca)
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
    if(l && r) return node;
    return l ? l : r;
}

// depth (edges) of target from node, -1 if not found
int depth(Node* node,int target){
    if(!node) return -1;
    if(node->val==target) return 0;
    int l = depth(node->left,target);
    if(l!=-1) return l+1;
    int r = depth(node->right,target);
    if(r!=-1) return r+1;
    return -1;
}

int distance(Node* root,int p,int q){
    Node* c = lca(root,p,q);
    return depth(c,p)+depth(c,q);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then distance(root,p,q)

    return 0;
}
