#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// Multisource BFS — push all sources first
int n,m,k;
vector<vector<int>> graph;
vector<int> dist;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    dist.assign(n+1,1e9);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin>>k; // number of sources
    queue<int> q;
    for(int i=0;i<k;i++){
        int src;
        cin>>src;
        dist[src]=0;
        q.push(src);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto t : graph[node]){
            if(dist[t]>dist[node]+1){
                dist[t]=dist[node]+1;
                q.push(t);
            }
        }
    }

    return 0;
}
