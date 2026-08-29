#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N * 2^N)
// SOS DP (Sum over Subsets): f[mask] = sum of a[sub] for all sub subset of mask
int n;
vector<ll> f;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    f.assign(1<<n,0);
    for(int mask=0;mask<(1<<n);mask++) cin>>f[mask]; // initial a[mask]

    for(int b=0;b<n;b++){
        for(int mask=0;mask<(1<<n);mask++){
            if(mask&(1<<b)) f[mask]+=f[mask^(1<<b)];
        }
    }

    // f[mask] now = sum over all submasks of mask

    return 0;
}
