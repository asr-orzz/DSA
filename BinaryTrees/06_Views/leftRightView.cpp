#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Left view = first node of each level, Right view = last node of each level
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<int> leftView(Node* root){
    vector<int> res;
    if(!root) return res;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            Node* cur = q.front();
            q.pop();
            if(i==0) res.push_back(cur->val);   // first of level
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return res;
}

vector<int> rightView(Node* root){
    vector<int> res;
    if(!root) return res;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            Node* cur = q.front();
            q.pop();
            if(i==sz-1) res.push_back(cur->val); // last of level
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then leftView(root) / rightView(root)

    return 0;
}
