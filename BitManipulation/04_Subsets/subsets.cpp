#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(N * 2^N)
// Generate all subsets using bitmask
int n;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    a.resize(n);
    for(auto &x : a) cin>>x;

    for(int mask=0;mask<(1<<n);mask++){
        vector<int> subset;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) subset.push_back(a[i]);
        }
        // process subset
    }

    return 0;
}
