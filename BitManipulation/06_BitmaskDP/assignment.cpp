#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(2^N * N)
// Assignment: assign N tasks to N people, min cost
// mask = set of assigned tasks; #bits = index of person being assigned
const ll INF = 1e18;

int n;
vector<vector<ll>> cost; // cost[person][task]
vector<ll> dp;

ll solve(int mask){
    int person = __builtin_popcount(mask);
    if(person==n) return 0;
    if(dp[mask]!=-1) return dp[mask];

    ll best=INF;
    for(int task=0;task<n;task++){
        if(mask&(1<<task)) continue;
        best=min(best, cost[person][task]+solve(mask|(1<<task)));
    }
    return dp[mask]=best;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    cost.assign(n,vector<ll>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>cost[i][j];

    dp.assign(1<<n,-1);
    ll ans = solve(0);

    return 0;
}
