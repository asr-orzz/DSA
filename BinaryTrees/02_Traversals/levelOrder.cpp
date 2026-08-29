#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Level Order (BFS) — grouped level by level
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> res;
    if(!root) return res;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        vector<int> level;

        for(int i=0;i<sz;i++){
            Node* cur = q.front();
            q.pop();
            level.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        res.push_back(level);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then levelOrder(root)

    return 0;
}
