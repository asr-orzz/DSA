#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// HLD: heavy-light decomposition
// head[v] = head of chain containing v
// pos[v]  = position of v in flattened order
int n,curPos=0;
vector<vector<int>> graph;
vector<int> par,depth,subtree,heavy,head,pos;

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

    if(heavy[node]!=-1) dfsHLD(heavy[node],h);

    for(auto t : graph[node]){
        if(t==par[node] || t==heavy[node]) continue;
        dfsHLD(t,t);
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
    subtree.assign(n+1,0);
    heavy.assign(n+1,-1);
    head.assign(n+1,0);
    pos.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsSize(1,0);
    dfsHLD(1,1);

    // to walk path u..v: while head[u]!=head[v] jump lighter head up
    // then both on same chain, use pos[u]..pos[v]

    return 0;
}
