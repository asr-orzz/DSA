#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// Shortest Path on DAG = topo order + relax edges
const ll INF = 1e18;

int n,m;
vector<vector<pair<int,int>>> graph;
vector<ll> dist;
vector<int> indegree;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    indegree.assign(n+1,0);
    dist.assign(n+1,INF);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        indegree[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto t : graph[node]){
            indegree[t.first]--;
            if(indegree[t.first]==0) q.push(t.first);
        }
    }

    // if(topo.size()!=n) not a DAG

    int src;
    cin>>src;
    dist[src]=0;

    for(auto node : topo){
        if(dist[node]==INF) continue; // very important
        for(auto t : graph[node]){
            int cur = t.first;
            int weight = t.second;
            dist[cur]=min(dist[cur],dist[node]+weight);
        }
    }

    return 0;
}
