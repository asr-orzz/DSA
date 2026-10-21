/*
Problem: Sereja and Brackets (Codeforces 380C)

You are given a bracket sequence s consisting of '(' and ')'
and q queries.

Each query contains two integers l and r:
    - Consider the substring s[l...r].
    - Find the length of the longest correct bracket
      subsequence within this substring.

A correct bracket subsequence:
    - Every '(' must be matched with a ')'.
    - Opening bracket must appear before closing bracket.
    - Brackets do not need to be contiguous.

Example:
    s = "(()())"
    Query: l=1, r=6
    Answer: 6

    Query: l=2, r=5
    Substring: "()()"
    Answer: 4

Input:
    s
    q
    l r  (q queries, 1-based indexing)

Output:
    For each query, print the maximum length of a
    correct bracket subsequence.

Approach: Segment Tree (Bracket Matching)

Each node stores:
    matched = Number of matched bracket pairs.
    open    = Number of unmatched '(' brackets.
    close   = Number of unmatched ')' brackets.

Merge two children a (left) and b (right):

    extra = min(a.open, b.close)

    matched = a.matched + b.matched + extra
    open    = a.open + b.open - extra
    close   = a.close + b.close - extra

Explanation:
    - Unmatched '(' from the left child can pair with
      unmatched ')' from the right child.
    - extra represents newly formed matching pairs.
    - Remaining brackets stay unmatched.

Leaf initialization:
    '(' -> node(0,1,0)
    ')' -> node(0,0,1)

Query(l,r):
    - Return the merged node for substring [l,r].
    - Answer = 2 * matched

Time Complexity:
    Build : O(n)
    Query : O(log n)
    Total : O(n + q log n)

Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n,q;
string s;

struct node{
    int matched;
    int open;
    int close;

    node(int m=0,int o=0,int c=0){
        matched=m;
        open=o;
        close=c;
    }
};

node merge(node a,node b){
    int extra = min(a.open,b.close);

    int m = a.matched+b.matched+extra;
    int o = a.open+b.open-extra;
    int c = a.close+b.close-extra;

    return node(m,o,c);
}

vector<node> tree;

void build(int id,int l,int r){
    if(l==r){
        if(s[l]=='(')
            tree[id]=node(0,1,0);
        else
            tree[id]=node(0,0,1);
        return;
    }

    int mid = (l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

node query(int id,int l,int r,int lq,int rq){
    if(r<lq or l>rq) return node();

    if(lq<=l and r<=rq) return tree[id];

    int mid = (l+r)/2;

    node a = query(2*id,l,mid,lq,rq);
    node b = query(2*id+1,mid+1,r,lq,rq);

    return merge(a,b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    n=s.size();

    cin>>q;
    tree.resize(4*n);

    build(1,0,n-1);

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;

        node ans = query(1,0,n-1,l,r);

        cout<<2*ans.matched<<"\n";
    }

    return 0;
}