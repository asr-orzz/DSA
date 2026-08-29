#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Count total nodes, leaf nodes, and sum of values
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

int countAll(Node* node){
    if(!node) return 0;
    return 1+countAll(node->left)+countAll(node->right);
}

int countLeaves(Node* node){
    if(!node) return 0;
    if(!node->left && !node->right) return 1;
    return countLeaves(node->left)+countLeaves(node->right);
}

ll sumNodes(Node* node){
    if(!node) return 0;
    return (ll)node->val+sumNodes(node->left)+sumNodes(node->right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then countAll / countLeaves / sumNodes

    return 0;
}
