#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Serialize / Deserialize using preorder with '#' for null
struct Node {
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=NULL; }
};

void serialize(Node* node,string &out){
    if(!node){
        out += "# ";
        return;
    }
    out += to_string(node->val) + " ";
    serialize(node->left,out);
    serialize(node->right,out);
}

Node* deserialize(istringstream &in){
    string tok;
    in>>tok;
    if(tok=="#") return NULL;

    Node* node = new Node(stoi(tok));
    node->left = deserialize(in);
    node->right = deserialize(in);
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    // string s; serialize(root,s);
    // istringstream in(s); Node* root2 = deserialize(in);

    return 0;
}
