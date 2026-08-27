#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N log N)
// Centroid Decomposition
int n;
vector<vector<int>> graph;
vector<int> subtree,vis;

void dfsSize(int node,int p){
    subtree[node]=1;
    for(auto t : graph[node]){
        if(t==p || vis[t]) continue;
        dfsSize(t,node);
        subtree[node]+=subtree[t];
    }
}

int dfsCentroid(int node,int p,int total){
    for(auto t : graph[node]){
        if(t==p || vis[t]) continue;
        if(subtree[t]>total/2) return dfsCentroid(t,node,total);
    }
    return node;
}

void collect(int node,int p,int d,vector<int> &buf){
    buf.push_back(d);
    for(auto t : graph[node]){
        if(t==p || vis[t]) continue;
        collect(t,node,d+1,buf);
    }
}

void decompose(int entry){
    dfsSize(entry,0);
    int c = dfsCentroid(entry,0,subtree[entry]);
    vis[c]=1;

    // process paths through centroid c
    for(auto t : graph[c]){
        if(vis[t]) continue;
        vector<int> childDist;
        collect(t,c,1,childDist);
        // combine with previous children for cross-subtree pairs
    }

    for(auto t : graph[c]){
        if(!vis[t]) decompose(t);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    subtree.assign(n+1,0);
    vis.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    decompose(1);

    return 0;
}
