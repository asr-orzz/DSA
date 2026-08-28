#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Centroid = node where every subtree size <= n/2
int n;
vector<vector<int>> graph;
vector<int> subtree;

void dfsSize(int node,int p){
    subtree[node]=1;
    for(auto t : graph[node]){
        if(t==p) continue;
        dfsSize(t,node);
        subtree[node]+=subtree[t];
    }
}

int dfsCentroid(int node,int p){
    for(auto t : graph[node]){
        if(t==p) continue;
        if(subtree[t]>n/2) return dfsCentroid(t,node);
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    subtree.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsSize(1,0);
    int centroid = dfsCentroid(1,0);

    return 0;
}
