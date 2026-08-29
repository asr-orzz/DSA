#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(H)
// BST insert
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* insert(Node* node,int key){
    if(!node) return new Node(key);
    if(key<node->val) node->left = insert(node->left,key);
    else if(key>node->val) node->right = insert(node->right,key);
    // equal -> ignore (no duplicates)
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root = insert(root,x);
    }

    return 0;
}
