#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(2^N * N^2)
// TSP — min cost to visit all nodes, start & end at 0
const ll INF = 1e18;

int n;
vector<vector<ll>> cost;
vector<vector<ll>> dp; // dp[mask][i] = min cost, visited=mask, currently at i

ll solve(int mask,int i){
    if(mask==(1<<n)-1) return cost[i][0]; // all visited -> return to start
    if(dp[mask][i]!=-1) return dp[mask][i];

    ll best=INF;
    for(int j=0;j<n;j++){
        if(mask&(1<<j)) continue;
        best=min(best, cost[i][j]+solve(mask|(1<<j),j));
    }
    return dp[mask][i]=best;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    cost.assign(n,vector<ll>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>cost[i][j];

    dp.assign(1<<n,vector<ll>(n,-1));
    ll ans = solve(1,0); // start at node 0, mask has only 0

    return 0;
}
