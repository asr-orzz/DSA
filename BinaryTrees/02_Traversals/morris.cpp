#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N), Space: O(1)
// Morris traversal — threads via inorder predecessor, no stack/recursion
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

void morrisInorder(Node* root){
    Node* cur = root;
    while(cur){
        if(!cur->left){
            cout<<cur->val<<" ";
            cur = cur->right;
        }
        else{
            Node* pre = cur->left;
            while(pre->right && pre->right!=cur) pre = pre->right;

            if(!pre->right){
                pre->right = cur;       // make thread
                cur = cur->left;
            }
            else{
                pre->right = NULL;      // remove thread
                cout<<cur->val<<" ";
                cur = cur->right;
            }
        }
    }
}

void morrisPreorder(Node* root){
    Node* cur = root;
    while(cur){
        if(!cur->left){
            cout<<cur->val<<" ";
            cur = cur->right;
        }
        else{
            Node* pre = cur->left;
            while(pre->right && pre->right!=cur) pre = pre->right;

            if(!pre->right){
                cout<<cur->val<<" ";    // print before going left
                pre->right = cur;
                cur = cur->left;
            }
            else{
                pre->right = NULL;
                cur = cur->right;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then morrisInorder(root) / morrisPreorder(root)

    return 0;
}
