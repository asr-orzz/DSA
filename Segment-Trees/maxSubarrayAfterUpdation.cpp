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