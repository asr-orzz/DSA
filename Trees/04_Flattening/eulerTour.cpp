#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Euler tour: tin/tout timestamps
// Subtree of v = all nodes u with tin[u] in [tin[v], tout[v]]
// Flat array euler[] for range queries (use SegmentTree folder separately)
int n,timer=0;
vector<vector<int>> graph;
vector<int> tin,tout,euler,par;

void dfs(int node,int p){
    par[node]=p;
    tin[node]=++timer;
    euler.push_back(node);

    for(auto t : graph[node]){
        if(t==p) continue;
        dfs(t,node);
    }
    tout[node]=timer;
}

bool inSubtree(int u,int v){
    // is u in subtree of v ?
    return tin[v]<=tin[u] && tout[u]<=tout[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    par.assign(n+1,0);
    euler.reserve(n);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0);

    // subtree range of v: [tin[v], tout[v]] on euler order / node array

    return 0;
}
