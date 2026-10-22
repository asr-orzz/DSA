#include<bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/1736

typedef long long int ll;

int n,q;
vector<ll> a;

struct node{
    ll sum;
    ll a,d;  // first term and common difference of lazy AP

    node(ll s=0,ll x=0,ll y=0){
        sum=s;
        a=x;
        d=y;
    }
};

vector<node> tree;

node merge(node a,node b){
    return node(a.sum+b.sum);
}

// Apply an AP update to the current node
void apply(int id,int l,int r,ll a,ll d){
    ll len=r-l+1;

    tree[id].sum += len*a + d*len*(len-1)/2;

    tree[id].a += a;
    tree[id].d += d;
}

// Push pending AP to children
void push(int id,int l,int r){
    if(l==r) return;

    ll a=tree[id].a;
    ll d=tree[id].d;

    if(a==0 and d==0) return;

    int mid=(l+r)/2;

    // Left child starts with a
    apply(2*id,l,mid,a,d);

    // Right child starts after (mid-l+1) terms
    apply(2*id+1,mid+1,r,a+(mid-l+1)*d,d);

    tree[id].a=0;
    tree[id].d=0;
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

// Add 1,2,3,... to range [lq,rq]
void update(int id,int l,int r,int lq,int rq){
    if(rq<l or r<lq) return;

    if(lq<=l and r<=rq){
        apply(id,l,r,l-lq+1,1);
        return;
    }

    push(id,l,r);

    int mid=(l+r)/2;

    update(2*id,l,mid,lq,rq);
    update(2*id+1,mid+1,r,lq,rq);

    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

// Range sum query
ll query(int id,int l,int r,int lq,int rq){
    if(rq<l or r<lq) return 0;

    if(lq<=l and r<=rq){
        return tree[id].sum;
    }

    push(id,l,r);

    int mid=(l+r)/2;

    return query(2*id,l,mid,lq,rq)
          +query(2*id+1,mid+1,r,lq,rq);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;

    a.resize(n+1);
    tree.resize(4*n+4);

    for(int i=1;i<=n;i++) cin>>a[i];

    build(1,1,n);

    while(q--){
        int type,l,r;
        cin>>type>>l>>r;

        if(type==1){
            update(1,1,n,l,r);
        }
        else{
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }

    return 0;
}