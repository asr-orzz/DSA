#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V * E)
// relax all edges (n-1) times
// works for Negative Edges and NegativeCycles
const ll INF = 1e18;

int n,m;
vector<vector<pair<int,int>>> graph;
vector<ll> dist;

bool negativeCycle=0;

void bellmanFord(int source){

    dist[source]=0;

    for(int i=1;i<=n-1;i++){

        for(int j=1;j<=n;j++){

            if(dist[j]==INF) continue; // very important

            for(auto t : graph[j]){
                int cur = t.first;
                int weight = t.second;

                dist[cur]=min(dist[cur],dist[j]+weight);
            }

        }
    }


    //for Checking Negative Cycles
    for(int j=1;j<=n;j++){
        if(dist[j]==INF) continue;

        for(auto t : graph[j]){
            int cur = t.first;
            int weight = t.second;

            if(dist[cur]>dist[j]+weight){
                negativeCycle=1;
                return;
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    dist.assign(n+1,INF);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    }
    
    int src;
    cin>>src;

    
    bellmanFord(src);


    return 0;
}
