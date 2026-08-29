#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Build tree from Inorder + Postorder
// postorder (from back) gives root; inorder splits left/right
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

vector<int> postorder,inorder;
unordered_map<int,int> pos;
int postIdx;

Node* build(int inL,int inR){
    if(inL>inR) return NULL;

    int rootVal = postorder[postIdx--];
    Node* root = new Node(rootVal);

    int mid = pos[rootVal];
    // right built before left (postorder consumed from back)
    root->right = build(mid+1,inR);
    root->left = build(inL,mid-1);
    return root;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    postorder.resize(n);
    inorder.resize(n);
    for(int i=0;i<n;i++){
        cin>>inorder[i];
        pos[inorder[i]]=i;
    }
    for(auto &x : postorder) cin>>x;

    postIdx = n-1;
    Node* root = build(0,n-1);

    return 0;
}
