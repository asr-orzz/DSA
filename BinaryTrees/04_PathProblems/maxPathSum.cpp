#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Max path sum (path may start/end anywhere, bends at one node)
ll best;

struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

// returns best straight downward gain from node
ll dfs(Node* node){
    if(!node) return 0;
    ll l = max(0LL,dfs(node->left));   // drop negative branches
    ll r = max(0LL,dfs(node->right));
    best = max(best,node->val + l + r); // bend at node
    return node->val + max(l,r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // best = LLONG_MIN; dfs(root); answer = best

    return 0;
}
