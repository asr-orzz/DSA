#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Zigzag / Spiral level order — alternate L->R and R->L
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<vector<int>> zigzag(Node* root){
    vector<vector<int>> res;
    if(!root) return res;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int sz = q.size();
        vector<int> level(sz);

        for(int i=0;i<sz;i++){
            Node* cur = q.front();
            q.pop();
            int idx = leftToRight ? i : sz-1-i;
            level[idx] = cur->val;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        res.push_back(level);
        leftToRight = !leftToRight;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then zigzag(root)

    return 0;
}
