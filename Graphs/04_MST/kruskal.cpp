#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(E log E)
// MST via Kruskal + DSU
int n,m;
vector<int> parent,sz;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

bool unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    parent.resize(n+1);
    sz.assign(n+1,1);
    for(int i=1;i<=n;i++) parent[i]=i;

    vector<array<int,3>> edges; // {w,u,v}
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }

    sort(edges.begin(),edges.end());

    ll mstCost=0;
    int taken=0;

    for(auto e : edges){
        int w=e[0],u=e[1],v=e[2];
        if(unite(u,v)){
            mstCost+=w;
            taken++;
        }
    }

    // if(taken!=n-1) graph not connected, no MST

    return 0;
}
