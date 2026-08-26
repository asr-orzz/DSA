#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

int n,m;
vector<vector<int>> graph;
vector<int> vis;
vector<int> topo;
bool cycle = false;

void dfs(int node,int par){

    vis[node]=2;
    for(auto t : graph[node]){

        // if(t==par) continue; //for undirected graph only

        if(vis[t]==1){ //forward edge
            dfs(t,node);
        }

        else if (vis[t]==2){ //back-edge
            //cycle-detected
            cycle = true;
        }   

        else{
            // cross-edge
        }   
    }
    vis[node]=3;
    topo.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;

    vis.assign(n+1,1);
    graph.resize(n+1);


    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==1) dfs(i,0);
    }
    
    if(cycle){
        //cycle-detected not DAG
    }
    else{
        reverse(topo.begin(),topo.end());
        for(int i=0;i<n;i++) cout<<topo[i]<<" ";
    }
 

    return 0;
}
