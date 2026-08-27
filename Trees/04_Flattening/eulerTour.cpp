#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Euler Tour: tin/tout
// u in subtree of v  <=>  tin[v] <= tin[u] && tout[u] <= tout[v]
int n,timer=0;
vector<vector<int>> graph;
vector<int> tin,tout,par;

void dfs(int node,int p){
    par[node]=p;
    tin[node]=++timer;

    for(auto t : graph[node]){
        if(t==p) continue;
        dfs(t,node);
    }
    tout[node]=timer;
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

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0);

    // subtree of v = nodes with tin in [tin[v], tout[v]]

    return 0;
}
