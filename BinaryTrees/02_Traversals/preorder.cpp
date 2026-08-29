#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Preorder: Root -> Left -> Right
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

void preRec(Node* node){
    if(!node) return;
    cout<<node->val<<" ";
    preRec(node->left);
    preRec(node->right);
}

void preIter(Node* root){
    if(!root) return;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* cur = st.top();
        st.pop();
        cout<<cur->val<<" ";

        // right pushed first so left is processed first
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then preRec(root) / preIter(root)

    return 0;
}
