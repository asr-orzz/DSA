#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Check two trees are identical (structure + values)
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

bool same(Node* a,Node* b){
    if(!a && !b) return true;
    if(!a || !b) return false;
    if(a->val!=b->val) return false;
    return same(a->left,b->left) && same(a->right,b->right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build a, b, then same(a,b)

    return 0;
}
