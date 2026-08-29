#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

// Time: O(1) per op
// Basic bit operations (0-indexed from LSB)
int getBit(int x,int i){
    return (x>>i)&1;
}

int setBit(int x,int i){
    return x | (1<<i);
}

int clearBit(int x,int i){
    return x & ~(1<<i);
}

int toggleBit(int x,int i){
    return x ^ (1<<i);
}

int updateBit(int x,int i,int val){
    // val is 0 or 1
    return (x & ~(1<<i)) | (val<<i);
}

bool isOdd(int x){
    return x&1;
}

bool isPowerOfTwo(int x){
    return x>0 && (x & (x-1))==0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int x,i;
    cin>>x>>i;
    // getBit(x,i), setBit(x,i), clearBit(x,i), toggleBit(x,i)

    return 0;
}
