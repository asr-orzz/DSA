#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// ------------------------------------------------------------
// Kth Smallest Segment Tree
//
// Queries:
// + x  -> Insert x
// - x  -> Remove one occurrence of x
// ? k  -> Find kth smallest element (1-indexed)
//
// Each node stores count of elements in its range.
//
// Time: O(log n) per query
// Space: O(n)
//
// Coordinate Compression used for large values of x.
// ------------------------------------------------------------

int n,q;
vector<int> a,t;

void update(int id,int l,int r,int pos,int val){
    if(pos<l or pos>r) return;

    if(l==r){
        t[id]+=val;
        return;
    }

    int mid=(l+r)/2;

    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);

    t[id]=t[2*id]+t[2*id+1];
}

int query(int id,int l,int r,int k){
    if(t[id]<k or k<=0) return -1;

    if(l==r) return l;

    int mid=(l+r)/2;

    if(t[2*id]>=k){
        return query(2*id,l,mid,k);
    }
    else{
        return query(2*id+1,mid+1,r,k-t[2*id]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;

    vector<pair<char,int>> queries;
    vector<int> values;

    for(int i=0;i<q;i++){
        char type;
        int x;
        cin>>type>>x;

        queries.push_back({type,x});

        if(type=='+' or type=='-'){
            values.push_back(x);
        }
    }

    sort(values.begin(),values.end());
    values.erase(unique(values.begin(),values.end()),values.end());

    n=values.size();
    t.resize(4*n+5,0);

    for(auto [type,x]:queries){

        if(type=='+'){
            int pos=lower_bound(values.begin(),values.end(),x)-values.begin();
            update(1,0,n-1,pos,1);
        }
        else if(type=='-'){
            int pos=lower_bound(values.begin(),values.end(),x)-values.begin();

            // Assumes x exists in the multiset
            update(1,0,n-1,pos,-1);
        }
        else if(type=='?'){
            if(n==0 or x<=0 or x>t[1]){
                cout<<-1<<"\n";
                continue;
            }

            int pos=query(1,0,n-1,x);
            cout<<values[pos]<<"\n";
        }
    }

    return 0;
}