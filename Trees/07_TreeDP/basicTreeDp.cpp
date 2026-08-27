#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Tree DP — max independent set
// dp0 = skip node, dp1 = take node
int n;
vector<vector<int>> graph;
vector<ll> dp0,dp1;

void dfs(int node,int p){
    dp0[node]=0;
    dp1[node]=1; // or value[node]

    for(auto t : graph[node]){
        if(t==p) continue;
        dfs(t,node);
        dp0[node]+=max(dp0[t],dp1[t]);
        dp1[node]+=dp0[t];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    dp0.assign(n+1,0);
    dp1.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0);
    ll ans = max(dp0[1],dp1[1]);

    return 0;
}
