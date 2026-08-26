#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O((V + E) log V)
// MST via Prim (priority queue)
const ll INF = 1e18;

int n,m;
vector<vector<pair<int,int>>> graph;
vector<ll> key;
vector<int> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    key.assign(n+1,INF);
    vis.assign(n+1,0);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    priority_queue<pair<ll,int>> pq; // {-key, node}
    key[1]=0;
    pq.push(make_pair(0,1));

    ll mstCost=0;
    int taken=0;

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        ll curKey = -temp.first;
        int node = temp.second;

        if(vis[node]) continue;
        vis[node]=1;
        mstCost+=curKey;
        taken++;

        for(auto t : graph[node]){
            int cur = t.first;
            int weight = t.second;
            if(!vis[cur] && weight<key[cur]){
                key[cur]=weight;
                pq.push(make_pair(-key[cur],cur));
            }
        }
    }

    // if(taken!=n) graph not connected, no MST

    return 0;
}
