#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// ------------------------------------------------------------
// Lazy Queries — Segment Tree with Lazy Propagation
//
// Given an array of n integers, process q queries:
//
// Type 1: 1 a b x
//         Increase every element in range [a,b] by x.
//
// Type 2: 2 a b x
//         Set every element in range [a,b] to x.
//
// Type 3: 3 a b
//         Find the sum of elements in range [a,b].
//
// Input:
// n q
// t1 t2 ... tn
// q queries of the above three types
//
// Constraints:
// 1 <= n,q <= 2*10^5
// 1 <= t[i],x <= 10^6
// 1 <= a <= b <= n
//
// Approach:
// Segment Tree + Lazy Propagation
//
// Each node maintains:
// sum    -> sum of its segment
// lz1    -> pending range addition
// lz2    -> pending range assignment
// hasSet -> whether an assignment is pending
//
// Important:
// 1. Addition accumulates with previous updates.
// 2. Assignment overrides all previous updates.
// 3. While pushing, apply assignment first, then addition.
//
// Time:  Build O(n)
//        Each update O(log n)
//        Each query O(log n)
//
// Space: O(n)
// ------------------------------------------------------------

int n,q;
vector<ll> a;

struct node{
    ll sum;
    ll lz1;       // addition
    ll lz2;       // assignment
    bool hasSet;

    node(ll s=0,ll l1=0,ll l2=0,bool h=false){
        sum=s;
        lz1=l1;
        lz2=l2;
        hasSet=h;
    }
};

vector<node> tree;

node merge(node a,node b){
    return node(a.sum+b.sum);
}

void applyAdd(int id,int l,int r,ll val){
    tree[id].sum += (r-l+1)*val;
    tree[id].lz1 += val;
}

void applySet(int id,int l,int r,ll val){
    tree[id].sum = (r-l+1)*val;
    tree[id].lz2 = val;
    tree[id].lz1 = 0;
    tree[id].hasSet = true;
}

void push(int id,int l,int r){
    if(l==r) return;

    int mid=(l+r)/2;

    // Push assignment first
    if(tree[id].hasSet){
        applySet(2*id,l,mid,tree[id].lz2);
        applySet(2*id+1,mid+1,r,tree[id].lz2);

        tree[id].hasSet=false;
    }

    // Push addition second
    if(tree[id].lz1 != 0){
        applyAdd(2*id,l,mid,tree[id].lz1);
        applyAdd(2*id+1,mid+1,r,tree[id].lz1);

        tree[id].lz1=0;
    }
}

void build(int id,int l,int r){
    if(l==r){
        tree[id]=node(a[l]);
        return;
    }

    int mid=(l+r)/2;

    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

void update1(int id,int l,int r,int lq,int rq,ll val,int type){
    if(rq<l or lq>r) return;

    if(lq<=l and r<=rq){
        if(type==1){
            applyAdd(id,l,r,val);
        }
        else{
            applySet(id,l,r,val);
        }
        return;
    }

    push(id,l,r);

    int mid=(l+r)/2;

    update1(2*id,l,mid,lq,rq,val,type);
    update1(2*id+1,mid+1,r,lq,rq,val,type);

    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

ll query(int id,int l,int r,int lq,int rq){
    if(rq<l or lq>r) return 0;

    if(lq<=l and r<=rq){
        return tree[id].sum;
    }

    push(id,l,r);

    int mid=(l+r)/2;

    return query(2*id,l,mid,lq,rq)
         + query(2*id+1,mid+1,r,lq,rq);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;

    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    tree.resize(4*n+3);

    build(1,1,n);

    while(q--){
        int type,l,r;
        cin>>type>>l>>r;

        if(type==3){
            cout<<query(1,1,n,l,r)<<"\n";
        }
        else{
            ll x;
            cin>>x;
            update1(1,1,n,l,r,x,type);
        }
    }

    return 0;
}