#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Tree hashing — compare rooted subtrees
int n;
const ll MOD = 1e9+7;
const ll BASE = 911382323;

vector<vector<int>> graph;
vector<ll> hashVal;

void dfs(int node,int p){
    hashVal[node]=1;
    for(auto t : graph[node]){
        if(t==p) continue;
        dfs(t,node);
        hashVal[node] = (hashVal[node]*BASE + hashVal[t])%MOD;
    }
    hashVal[node] = (hashVal[node]*BASE + 1)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    hashVal.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0);

    // hashVal[v] identifies rooted subtree at v

    return 0;
}
