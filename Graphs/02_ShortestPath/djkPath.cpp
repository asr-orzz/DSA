#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O((V + E) log V)
// Dijkstra + path reconstruction via parent[]
int n,m;
vector<vector<pair<int,int>>> graph;
vector<int> dist,parent;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    dist.assign(n+1,1e9);
    parent.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    }

    int src,dest;
    cin>>src>>dest;
    
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,src));
    dist[src]=0;

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        int curDist = -temp.first;
        int node = temp.second;
        
        if(curDist>dist[node]) continue;
        
        for(auto t : graph[node]){
            int cur = t.first;
            int weight = t.second;

            if(dist[cur] > curDist + weight){
                dist[cur]= curDist + weight;
                parent[cur]=node;
                pq.push(make_pair(-dist[cur],cur));
            }
        }
    }

    if(dist[dest]==1e9){
        // unreachable
    }
    else{
        vector<int> path;
        for(int cur=dest;cur!=-1;cur=parent[cur]){
            path.push_back(cur);
        }
        reverse(path.begin(),path.end());
        // path = src ... dest
    }

    return 0;
}
