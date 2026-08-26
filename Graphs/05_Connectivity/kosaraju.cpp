#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// SCC via Kosaraju + condensation graph
int n,m;
vector<vector<int>> graph,rev;
vector<int> vis,order,comp;

void dfs1(int node){
    vis[node]=1;
    for(auto t : graph[node]){
        if(!vis[t]) dfs1(t);
    }
    order.push_back(node);
}

void dfs2(int node,int c){
    comp[node]=c;
    for(auto t : rev[node]){
        if(comp[t]==-1) dfs2(t,c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    rev.resize(n+1);
    vis.assign(n+1,0);
    comp.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        rev[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs1(i);
    }

    reverse(order.begin(),order.end());

    int sccCount=0;
    for(auto node : order){
        if(comp[node]==-1){
            dfs2(node,sccCount);
            sccCount++;
        }
    }

    // condensation DAG (edges between different SCCs)
    vector<vector<int>> dag(sccCount);
    for(int u=1;u<=n;u++){
        for(auto v : graph[u]){
            if(comp[u]!=comp[v]){
                dag[comp[u]].push_back(comp[v]);
            }
        }
    }

    return 0;
}
