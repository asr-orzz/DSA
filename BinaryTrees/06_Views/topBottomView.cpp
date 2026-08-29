#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N log N)
// Top/Bottom view by horizontal distance (hd): left = hd-1, right = hd+1
// BFS so ties per column resolve by level order
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<int> topView(Node* root){
    vector<int> res;
    if(!root) return res;
    map<int,int> col;                 // hd -> first value seen
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto [cur,hd] = q.front();
        q.pop();
        if(col.find(hd)==col.end()) col[hd]=cur->val; // keep topmost
        if(cur->left) q.push({cur->left,hd-1});
        if(cur->right) q.push({cur->right,hd+1});
    }
    for(auto &p : col) res.push_back(p.second);
    return res;
}

vector<int> bottomView(Node* root){
    vector<int> res;
    if(!root) return res;
    map<int,int> col;                 // hd -> latest value seen
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto [cur,hd] = q.front();
        q.pop();
        col[hd]=cur->val;             // overwrite -> keep lowest
        if(cur->left) q.push({cur->left,hd-1});
        if(cur->right) q.push({cur->right,hd+1});
    }
    for(auto &p : col) res.push_back(p.second);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then topView(root) / bottomView(root)

    return 0;
}
