#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Root tree at 1: parent, depth, height, subtree size
// Trees prefer DFS (same info as BFS; easier for DP / reroot / aggregates)
int n;
vector<vector<int>> graph;
vector<int> par,depth,height,subtree;

void dfs(int node,int p){
    par[node]=p;
    subtree[node]=1;
    height[node]=0;

    for(auto t : graph[node]){
        if(t==p) continue;
        depth[t]=depth[node]+1;
        dfs(t,node);
        subtree[node]+=subtree[t];
        height[node]=max(height[node],height[t]+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    par.assign(n+1,0);
    depth.assign(n+1,0);
    height.assign(n+1,0);
    subtree.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0);

    // par[v], depth[v], height[v], subtree[v] ready
    // subtree aggregate example: sum of values in subtree via another dfs

    return 0;
}
