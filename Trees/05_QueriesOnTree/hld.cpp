#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N log N) preprocess, O(log^2 N) path query
// HLD: decompose tree into heavy-light chains
// Path queries/updates: plug SegmentTree on pos[] array (separate folder)
int n,curPos=0;
vector<vector<int>> graph;
vector<int> par,depth,subtree,heavy,head,pos,rev;
vector<ll> base; // values at pos (for segtree later)

void dfsSize(int node,int p){
    par[node]=p;
    subtree[node]=1;
    heavy[node]=-1;
    int best=0;

    for(auto t : graph[node]){
        if(t==p) continue;
        depth[t]=depth[node]+1;
        dfsSize(t,node);
        subtree[node]+=subtree[t];
        if(subtree[t]>best){
            best=subtree[t];
            heavy[node]=t;
        }
    }
}

void dfsHLD(int node,int h){
    head[node]=h;
    pos[node]=++curPos;
    rev[curPos]=node;
    base[curPos]=0; // fill with node value

    if(heavy[node]!=-1) dfsHLD(heavy[node],h);

    for(auto t : graph[node]){
        if(t==par[node] || t==heavy[node]) continue;
        dfsHLD(t,t);
    }
}

// query path u..v — replace loop body with segtree query on [pos[head], pos[node]]
ll queryPath(int u,int v){
    ll ans=0;
    while(head[u]!=head[v]){
        if(depth[head[u]]<depth[head[v]]) swap(u,v);
        int h = head[u];
        // ans += segtree.query(pos[h], pos[u])
        u = par[h];
    }
    if(depth[u]>depth[v]) swap(u,v);
    // ans += segtree.query(pos[u], pos[v])
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    par.assign(n+1,0);
    depth.assign(n+1,0);
    subtree.assign(n+1,0);
    heavy.assign(n+1,-1);
    head.assign(n+1,0);
    pos.assign(n+1,0);
    rev.assign(n+1,0);
    base.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsSize(1,0);
    dfsHLD(1,1);

    // pos[] linearizes tree; use SegmentTree folder for range ops

    return 0;
}
