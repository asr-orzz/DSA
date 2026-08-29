#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(3^N) over all masks (each pair (mask,submask) once)
// Iterate all submasks of a given mask
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int mask;
    cin>>mask;

    // submasks of a single mask (includes mask, excludes 0 in this loop form)
    for(int sub=mask; sub>0; sub=(sub-1)&mask){
        // process sub
    }
    // sub==0 (empty) handled separately if needed

    // classic use: iterate every mask and its submasks -> O(3^n)
    int n;
    cin>>n;
    for(int m=0;m<(1<<n);m++){
        for(int s=m; s>0; s=(s-1)&m){
            // (m, s) pair
        }
    }

    return 0;
}
