#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// All root-to-leaf paths + sum of root-to-leaf numbers
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<vector<int>> paths;
vector<int> cur;

void dfs(Node* node){
    if(!node) return;
    cur.push_back(node->val);

    if(!node->left && !node->right){
        paths.push_back(cur);
    }
    else{
        dfs(node->left);
        dfs(node->right);
    }
    cur.pop_back();
}

// sum of numbers formed along each root->leaf path
int sumNumbers(Node* node,int val){
    if(!node) return 0;
    val = val*10 + node->val;
    if(!node->left && !node->right) return val;
    return sumNumbers(node->left,val)+sumNumbers(node->right,val);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, dfs(root) fills paths; sumNumbers(root,0)

    return 0;
}
