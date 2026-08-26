#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N log N) — small-to-large merging on tree
// DSU on Tree: efficient subtree frequency / distinct queries
int n;
vector<vector<int>> graph;
vector<int> subtree,heavy,euler,first;
vector<int> freq,ans;
vector<int> col;
int timer=0;

void dfsSize(int node,int p){
    subtree[node]=1;
    heavy[node]=-1;
    int best=0;
    for(auto t : graph[node]){
        if(t==p) continue;
        dfsSize(t,node);
        subtree[node]+=subtree[t];
        if(subtree[t]>best){
            best=subtree[t];
            heavy[node]=t;
        }
    }
}

void addSubtree(int node,int p,int h,bool keep){
    freq[col[node]]++;
    // update ans from freq change

    for(auto t : graph[node]){
        if(t==p || t==h) continue;
        addSubtree(t,node,h,keep);
    }

    if(!keep){
        while(timer>first[node]){
            timer--;
            freq[col[euler[timer]]]--;
        }
    }
}

void dfs(int node,int p,bool keep){
    for(auto t : graph[node]){
        if(t==p || t==heavy[node]) continue;
        dfs(t,node,0);
    }

    if(heavy[node]!=-1) dfs(heavy[node],node,1);

    addSubtree(node,p,heavy[node],1);
    ans[node]=0; // replace with answer derived from freq

    if(!keep){
        while(timer>first[node]){
            timer--;
            freq[col[euler[timer]]]--;
        }
    }
}

void dfsEuler(int node,int p){
    first[node]=timer;
    euler[timer++]=node;
    if(heavy[node]!=-1) dfsEuler(heavy[node],node);
    for(auto t : graph[node]){
        if(t==p || t==heavy[node]) continue;
        dfsEuler(t,node);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    graph.resize(n+1);
    subtree.assign(n+1,0);
    heavy.assign(n+1,-1);
    euler.assign(n+1,0);
    first.assign(n+1,0);
    freq.assign(n+1,0);
    ans.assign(n+1,0);
    col.assign(n+1,0);

    for(int i=1;i<=n;i++) cin>>col[i];

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfsSize(1,0);
    dfsEuler(1,0);
    dfs(1,0,1);

    return 0;
}
