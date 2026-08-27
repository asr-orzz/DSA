#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Rerooting DP — sum of distances from every root
int n;
vector<vector<int>> graph;
vector<int> subtree;
vector<ll> dpDown,dpAll;

void dfsSize(int node,int p){
    subtree[node]=1;
    for(auto t : graph[node]){
        if(t==p) continue;
        dfsSize(t,node);
        subtree[node]+=subtree[t];
    }
}

void dfs1(int node,int p){
    dpDown[node]=0;
    for(auto t : graph[node]){
        if(t==p) continue;
        dfs1(t,node);
        dpDown[node]+=dpDown[t]+subtree[t];
    }
}

void dfs2(int node,int p){
    for(auto t : graph[node]){
        if(t==p) continue;
        // reroot from node to t
        dpAll[t]=dpAll[node]-subtree[t]+(n-subtree[t]);
        dfs2(t,node);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    subtree.assign(n+1,0);
    dpDown.assign(n+1,0);
    dpAll.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsSize(1,0);
    dfs1(1,0);
    dpAll[1]=dpDown[1];
    dfs2(1,0);

    // dpAll[v] = sum of distances from v to all nodes

    return 0;
}
