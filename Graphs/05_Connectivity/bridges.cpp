#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// Bridges (critical edges) via Tarjan discovery / lowlink
int n,m;
vector<vector<int>> graph;
vector<int> tin,low;
vector<int> vis;
int timer=0;
vector<pair<int,int>> bridges;

void dfs(int node,int par){
    vis[node]=1;
    tin[node]=low[node]=++timer;

    for(auto t : graph[node]){
        if(t==par) continue;
        if(vis[t]){
            low[node]=min(low[node],tin[t]); // back-edge
        }
        else{
            dfs(t,node);
            low[node]=min(low[node],low[t]);
            if(low[t]>tin[node]){
                bridges.push_back(make_pair(node,t)); // bridge
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    vis.assign(n+1,0);
    tin.assign(n+1,-1);
    low.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,0);
    }

    return 0;
}
