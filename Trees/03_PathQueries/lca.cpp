#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N log N) preprocess, O(log N) query
// Binary Lifting LCA
int n,q,LOG;
vector<vector<int>> graph,up;
vector<int> depth;

void dfs(int node,int par){
    up[node][0]=par;
    for(int j=1;j<LOG;j++){
        if(up[node][j-1]!=-1)
            up[node][j]=up[up[node][j-1]][j-1];
    }
    for(auto t : graph[node]){
        if(t==par) continue;
        depth[t]=depth[node]+1;
        dfs(t,node);
    }
}

int kthAncestor(int node,int k){
    for(int j=0;j<LOG;j++){
        if(k&(1<<j)) node=up[node][j];
    }
    return node;
}

int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);

    int diff=depth[a]-depth[b];
    for(int j=0;j<LOG;j++){
        if(diff&(1<<j)) a=up[a][j];
    }

    if(a==b) return a;

    for(int j=LOG-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];
}

int dist(int a,int b){
    int c = lca(a,b);
    return depth[a]+depth[b]-2*depth[c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    LOG=0;
    while((1<<LOG)<=n) LOG++;

    graph.resize(n+1);
    up.assign(n+1,vector<int>(LOG,-1));
    depth.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,-1);

    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
        // dist(a,b), kthAncestor(a,k)
    }

    return 0;
}
