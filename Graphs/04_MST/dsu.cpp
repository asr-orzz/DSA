#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: nearly O(1) per op with path compression + union by size
int n,m;
vector<int> parent,sz;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]); // path compression
}

void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b); // union by size
    parent[b]=a;
    sz[a]+=sz[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    parent.resize(n+1);
    sz.assign(n+1,1);
    for(int i=1;i<=n;i++) parent[i]=i;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        unite(u,v);
    }

    // components = count of i where find(i)==i

    return 0;
}
