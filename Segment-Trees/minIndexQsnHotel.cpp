/*
Problem: Hotel Queries (CSES)

You are given n hotels and q groups of customers.

Each hotel has a[i] available rooms.
Each group requires X rooms.

For every group:
    - Find the leftmost hotel having at least X available rooms.
    - Allocate X rooms to that group.
    - Decrease that hotel's available rooms by X.
    - If no hotel has enough rooms, print 0.

Input:
    n q
    a[0] a[1] ... a[n-1]
    X1 X2 ... Xq

Output:
    For each group, print the 1-based index of the
    leftmost hotel that can accommodate the group.
    Print 0 if no such hotel exists.

Approach: Segment Tree (Range Maximum + First >= X)

Each node stores:
    maxVal = Maximum available rooms in its segment.

Merge two children:
    maxVal = max(left.maxVal, right.maxVal)

Query(X):
    - If tree[id].maxVal < X, return -1.
    - If leaf node, return its index.
    - If left child maxVal >= X, search left.
    - Otherwise, search right.

Update(pos, X):
    a[pos] -= X
    Update maximum values along the path.

Time Complexity:
    Build  : O(n)
    Query  : O(log n)
    Update : O(log n)
    Total  : O(n + q log n)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n,q;
vector<int> a;

struct node{
    int maxVal;
    node(int maxi=0){
        maxVal=maxi;
    }
};

node merge(node a,node b){
    return node(max(a.maxVal,b.maxVal));
}

vector<node> tree;

void build(int id,int l,int r){
    if(l==r){
        tree[id]=node(a[l]);
        return;
    }

    int mid = (l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

void update(int id,int l,int r,int pos,int val){
    if(pos<l or pos>r) return;
    if(l==r){
        int m = tree[id].maxVal;
        tree[id]=node(m-val);
        return;
    }

    int mid = (l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

int query(int id,int l,int r,int X){
    if(tree[id].maxVal<X){
        return -1;
    }
    if(l==r){
        return l;
    }
    int mid = (l+r)/2;
    if(tree[2*id].maxVal>=X) return query(2*id,l,mid,X);
    else return query(2*id+1,mid+1,r,X);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    a.resize(n);
    tree.resize(4*n);

    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);

    for(int i=0;i<q;i++){
        int X;
        cin>>X;
        int index = query(1,0,n-1,X);
        if(index!=-1){
            cout<<index+1<<" ";
            update(1,0,n-1,index,X);
        }
        else cout<<0<<" ";
    }

    return 0;
}