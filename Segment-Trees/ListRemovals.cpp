//https://cses.fi/problemset/task/1144
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
vector<int> a,b;
vector<int> t;

void build(int id,int l,int r){
    if(l==r){
        t[id]=b[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=t[2*id]+t[2*id+1];
}

void remove(int id,int l,int r,int pos){
    if(pos<l or pos>r) return;

    if(l==r){
        t[id]=0;
        b[l]=0;
        return;
    }

    int mid = (l+r)/2;
    remove(2*id,l,mid,pos);
    remove(2*id+1,mid+1,r,pos);

    t[id]=t[2*id]+t[2*id+1];
}

int query(int id,int l,int r,int X){
    if(l==r) return l;

    int mid = (l+r)/2;

    if(t[2*id]>=X)
        return query(2*id,l,mid,X);
    else
        return query(2*id+1,mid+1,r,X-t[2*id]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    t.resize(4*n+3);
    b.assign(n+1,1);

    build(1,1,n);

    for(int i=0;i<n;i++){
        int p;
        cin>>p;

        int idx = query(1,1,n,p);

        cout<<a[idx]<<" ";
        remove(1,1,n,idx);
    }

    return 0;
}