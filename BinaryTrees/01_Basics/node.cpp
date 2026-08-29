#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Binary Tree node + build from level-order input
// Input: m, then m tokens (level order), -1 = null child
// terms: root(top), leaf(no child), height(edges root->deepest), depth(edges root->node)
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* build(){
    int m;
    cin>>m;
    if(m==0) return NULL;

    vector<int> a(m);
    for(auto &x : a) cin>>x;

    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    int i=1;
    while(!q.empty() && i<m){
        Node* cur = q.front();
        q.pop();

        if(i<m && a[i]!=-1){
            cur->left = new Node(a[i]);
            q.push(cur->left);
        }
        i++;

        if(i<m && a[i]!=-1){
            cur->right = new Node(a[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    Node* root = build();

    return 0;
}
