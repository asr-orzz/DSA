#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N log N)
// DSU on Tree (Sack) — small-to-large
int n;
vector<vector<int>> graph;
vector<int> subtree,heavy,col,freq,ans;
int curDistinct=0;

void dfsSize(int node,int p){
    subtree[node]=1;
    heavy[node]=-1;
    int best=0;

    for(auto t : graph[node]){
        if(t==p) continue;
        dfsSize(t,node);
        subtree[node]+=subtree[t];
        if(subtree[t]>best){
            best=subtree[t];
            heavy[node]=t;
        }
    }
}

void add(int node,int p,int x){
    // x = +1 add, x = -1 remove
    if(x==1){
        if(freq[col[node]]==0) curDistinct++;
        freq[col[node]]++;
    }
    else{
        freq[col[node]]--;
        if(freq[col[node]]==0) curDistinct--;
    }

    for(auto t : graph[node]){
        if(t==p) continue;
        add(t,node,x);
    }
}

void dfs(int node,int p,int keep){
    // light children first — discard
    for(auto t : graph[node]){
        if(t==p || t==heavy[node]) continue;
        dfs(t,node,0);
    }

    // heavy child — keep
    if(heavy[node]!=-1) dfs(heavy[node],node,1);

    // add node + light subtrees
    if(freq[col[node]]==0) curDistinct++;
    freq[col[node]]++;

    for(auto t : graph[node]){
        if(t==p || t==heavy[node]) continue;
        add(t,node,1);
    }

    ans[node]=curDistinct;

    // if not keep — remove whole subtree
    if(!keep) add(node,p,-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    subtree.assign(n+1,0);
    heavy.assign(n+1,-1);
    col.assign(n+1,0);
    freq.assign(n+1,0);
    ans.assign(n+1,0);

    for(int i=1;i<=n;i++) cin>>col[i];

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsSize(1,0);
    dfs(1,0,1);

    return 0;
}
