#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Inorder: Left -> Root -> Right  (sorted order in a BST)
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

void inRec(Node* node){
    if(!node) return;
    inRec(node->left);
    cout<<node->val<<" ";
    inRec(node->right);
}

void inIter(Node* root){
    stack<Node*> st;
    Node* cur = root;

    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cout<<cur->val<<" ";
        cur = cur->right;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then inRec(root) / inIter(root)

    return 0;
}
