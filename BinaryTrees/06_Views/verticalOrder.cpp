#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N log N)
// Vertical order: group by hd; ties by (row, value)
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<vector<int>> verticalOrder(Node* root){
    vector<vector<int>> res;
    if(!root) return res;

    // hd -> row -> multiset of values
    map<int,map<int,multiset<int>>> col;
    queue<tuple<Node*,int,int>> q; // node, hd, row
    q.push({root,0,0});

    while(!q.empty()){
        auto [cur,hd,row] = q.front();
        q.pop();
        col[hd][row].insert(cur->val);
        if(cur->left) q.push({cur->left,hd-1,row+1});
        if(cur->right) q.push({cur->right,hd+1,row+1});
    }

    for(auto &c : col){
        vector<int> line;
        for(auto &r : c.second)
            for(int v : r.second) line.push_back(v);
        res.push_back(line);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then verticalOrder(root)

    return 0;
}
