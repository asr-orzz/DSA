#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(V + E)
// Euler Path / Circuit via Hierholzer (undirected)
// Circuit: all degrees even; Path: exactly 0 or 2 odd degrees
int n,m;
vector<vector<pair<int,int>>> graph; // {to, edgeId}
vector<int> used;
vector<int> path;

void dfs(int node){
    while(!graph[node].empty()){
        auto t = graph[node].back();
        graph[node].pop_back();
        int cur = t.first;
        int id = t.second;
        if(used[id]) continue;
        used[id]=1;
        dfs(cur);
    }
    path.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    graph.resize(n+1);
    used.assign(m,0);
    vector<int> deg(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(make_pair(v,i));
        graph[v].push_back(make_pair(u,i));
        deg[u]++;
        deg[v]++;
    }

    vector<int> odd;
    for(int i=1;i<=n;i++){
        if(deg[i]&1) odd.push_back(i);
    }

    // if(odd.size()!=0 && odd.size()!=2) no Euler path
    // if(odd.size()!=0) no Euler circuit

    int start=1;
    if(odd.size()==2) start=odd[0];
    else{
        for(int i=1;i<=n;i++){
            if(deg[i]>0){ start=i; break; }
        }
    }

    dfs(start);
    reverse(path.begin(),path.end());

    // if(path.size()!=m+1) graph not connected (ignoring isolates)

    return 0;
}
