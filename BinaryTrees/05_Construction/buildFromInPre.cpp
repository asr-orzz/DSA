#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Build tree from Inorder + Preorder
// preorder gives root; inorder splits left/right
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<int> preorder,inorder;
unordered_map<int,int> pos; // value -> index in inorder
int preIdx=0;

Node* build(int inL,int inR){
    if(inL>inR) return NULL;

    int rootVal = preorder[preIdx++];
    Node* root = new Node(rootVal);

    int mid = pos[rootVal];
    root->left = build(inL,mid-1);
    root->right = build(mid+1,inR);
    return root;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    preorder.resize(n);
    inorder.resize(n);
    for(auto &x : preorder) cin>>x;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
        pos[inorder[i]]=i;
    }

    Node* root = build(0,n-1);

    return 0;
}
