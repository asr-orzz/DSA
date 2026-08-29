#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Flatten binary tree to a right-skewed linked list (preorder), in place
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

void flatten(Node* root){
    Node* cur = root;
    while(cur){
        if(cur->left){
            // find rightmost node of left subtree
            Node* pre = cur->left;
            while(pre->right) pre = pre->right;

            pre->right = cur->right;  // attach right subtree after it
            cur->right = cur->left;   // move left subtree to right
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build root, then flatten(root)

    return 0;
}
