#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(H + k)
// Kth smallest in BST = kth node of inorder traversal
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

int kthSmallest(Node* root,int k){
    stack<Node*> st;
    Node* cur = root;

    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        if(--k==0) return cur->val;
        cur = cur->right;
    }
    return -1; // k out of range
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build BST root, then kthSmallest(root,k)
    // kth largest = reverse inorder (right first)

    return 0;
}
