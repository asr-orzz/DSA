#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// Cycle detection in Undirected Graph
int n,m;
vector<vector<int>> graph;
vector<int> vis;
bool cycle=0;

void dfs(int node,int par){
    vis[node]=1;
    for(auto t : graph[node]){
        if(t==par) continue;
        if(vis[t]){
            cycle=1;
            return;
        }
        dfs(t,node);
        if(cycle) return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    vis.assign(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,0);
    }
    
    // if(cycle) cycle-detected

    return 0;
}
