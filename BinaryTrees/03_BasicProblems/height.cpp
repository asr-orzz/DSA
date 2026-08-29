#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Height = number of edges on longest root->leaf path
// (return nodes-count version by starting leaf at 1)
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

int height(Node* node){
    if(!node) return -1; // use 0 for "count of nodes" convention
    return 1+max(height(node->left),height(node->right));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then height(root)

    return 0;
}
