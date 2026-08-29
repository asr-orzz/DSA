#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Postorder: Left -> Right -> Root
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

void postRec(Node* node){
    if(!node) return;
    postRec(node->left);
    postRec(node->right);
    cout<<node->val<<" ";
}

// two stacks: reverse of (Root -> Right -> Left)
void postIter2(Node* root){
    if(!root) return;
    stack<Node*> a,b;
    a.push(root);

    while(!a.empty()){
        Node* cur = a.top();
        a.pop();
        b.push(cur);
        if(cur->left) a.push(cur->left);
        if(cur->right) a.push(cur->right);
    }

    while(!b.empty()){
        cout<<b.top()->val<<" ";
        b.pop();
    }
}

// single stack
void postIter1(Node* root){
    stack<Node*> st;
    Node* cur = root;
    Node* last = NULL;

    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        Node* peek = st.top();
        if(peek->right && last!=peek->right){
            cur = peek->right;
        }
        else{
            cout<<peek->val<<" ";
            last = peek;
            st.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then postRec / postIter1 / postIter2

    return 0;
}
