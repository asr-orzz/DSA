#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Diameter = longest path (in edges) between any two nodes
int diameter=0;

struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

int height(Node* node){
    if(!node) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    diameter = max(diameter,lh+rh); // path through this node
    return 1+max(lh,rh);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, height(root), answer = diameter

    return 0;
}
