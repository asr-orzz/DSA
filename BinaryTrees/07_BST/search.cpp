#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(H)
// BST search + min/max
// BST: left < node < right for every node
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* search(Node* node,int key){
    while(node && node->val!=key){
        node = key<node->val ? node->left : node->right;
    }
    return node;
}

Node* findMin(Node* node){
    while(node && node->left) node = node->left;
    return node;
}

Node* findMax(Node* node){
    while(node && node->right) node = node->right;
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // build BST root, then search / findMin / findMax

    return 0;
}
