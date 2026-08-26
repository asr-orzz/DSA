#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N)
// Tree diameter via two DFS from farthest node
int n;
vector<vector<int>> graph;
vector<int> dist;

void dfsDist(int node,int p,int d){
    dist[node]=d;
    for(auto t : graph[node]){
        if(t==p) continue;
        dfsDist(t,node,d+1);
    }
}

int farthest(){
    int node=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[node]) node=i;
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    dist.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsDist(1,0,0);
    int u = farthest();
    dfsDist(u,0,0);
    int v = farthest();
    int diameter = dist[v]; // length of longest path = u ... v

    return 0;
}
