#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

//for topological Ordering on DAG
//remove indegree==0 nodes until all removed 
int n,m;
vector<vector<int>> graph;
vector<int> indegree;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    indegree.assign(n+1,0);


    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }  

    vector<int> topoOrder;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        
        for(auto t : graph[node]){
            indegree[t]--;
            if(indegree[t]==0) q.push(t);  
        }
        
    }
    
    if(topoOrder.size()!=n){
        //cycle-detected not DAG
    }
    else{
        for(int i=0;i<n;i++) cout<<topoOrder[i]<<" ";
    }

    return 0;
}