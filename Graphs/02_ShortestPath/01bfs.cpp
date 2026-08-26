#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
int n,m;
vector<vector<pair<int,int>>> graph;
vector<int> dist;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    dist.assign(n+1,1e9);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    }

    int src;
    cin>>src;
    
    deque<int> dq;
    dq.push_back(src);
    dist[src]=0;

    while(!dq.empty()){
        int node = dq.front();
        dq.pop_front();
        
        for(auto t : graph[node]){

            int cur = t.first;
            int weight= t.second;

            if(dist[cur]>dist[node]+weight){ //relaxing nodes
                dist[cur]=dist[node]+weight;
                if(weight==0) dq.push_front(cur);
                else dq.push_back(cur);
            }
        }
    }

    return 0;
}