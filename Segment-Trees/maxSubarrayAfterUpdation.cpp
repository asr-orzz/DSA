/*
Problem: Subarray Sum Queries (CSES)

You are given an array of n integers and q queries.

Each query contains two integers k and x:
    - Update a[k] = x.
    - After each update, print the maximum subarray sum
      of the entire array.

A subarray must be contiguous.
An empty subarray is allowed, so the answer is at least 0.

Input:
    n q
    a[0] a[1] ... a[n-1]
    k x   (q queries, 1-based indexing)

Output:
    After each update, print the maximum subarray sum.

Approach: Segment Tree

Each node stores:
    maxVal   = Maximum subarray sum in its segment
    lSum     = Maximum prefix sum
    rSum     = Maximum suffix sum
    totalSum = Sum of all elements in the segment

Merge two children:
    maxVal = max({left.maxVal, right.maxVal,
                  left.rSum + right.lSum})

    lSum = max(left.lSum, left.totalSum + right.lSum)
    rSum = max(right.rSum, right.totalSum + left.rSum)
    totalSum = left.totalSum + right.totalSum

Time Complexity:
    Build  : O(n)
    Update : O(log n)
    Query  : O(1), answer stored at tree[1].maxVal

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n,q;
vector<int> a;

struct node{

    ll maxVal;
    ll lSum;
    ll rSum;
    ll totalSum;

    node(ll m=0,ll l=0,ll r=0,ll t=0){
        maxVal=m;
        lSum=l;
        rSum=r;
        totalSum=t;
    }
    
};

node merge(node a,node b){
    ll m = max(max(a.maxVal,b.maxVal),a.rSum+b.lSum);
    ll t = a.totalSum+b.totalSum;
    ll l = max(a.lSum,a.totalSum+b.lSum);
    ll r = max(b.rSum,b.totalSum+a.rSum);

    return node(m,l,r,t);
}

vector<node> tree;

void build(int id,int l,int r){
    if(l==r){
        tree[id]=node(max(a[l],0),max(a[l],0),max(a[l],0),a[l]);
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
        tree[id]=node(max(val,0),max(val,0),max(val,0),val);
        a[l]=val;
        return;
    }

    int mid = (l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
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
        int k,x;
        cin>>k>>x;
        k--;
        update(1,0,n-1,k,x);
        cout<<tree[1].maxVal<<"\n";
    }


    return 0;
}