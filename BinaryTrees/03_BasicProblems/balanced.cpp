#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Height-balanced: |lh - rh| <= 1 at every node
// return height, or -1 if unbalanced (short-circuit)
bool balanced=true;

struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

int check(Node* node){
    if(!node) return 0;
    int lh = check(node->left);
    int rh = check(node->right);
    if(abs(lh-rh)>1) balanced=false;
    return 1+max(lh,rh);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, check(root), answer = balanced

    return 0;
}
