#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void solve(){
    ll n,x,y;
    cin>>n>>y>>x;
    vector<vll> fx(x);
    ll k;
    for(int i=0;i<n;i+=1){
        cin>>k;
        fx[k%x].push_back(k);
    }
    ll ans=0;
    for(int i=0;i<x;i+=1){
        vll c(y,0);
        for(auto &j:fx[i])
            c[j%y]+=1;
        for(int k=1;k<(y+1)/2;k+=1)
            ans+=(c[k]*c[y-k]);
        ans+=(c[0]*(c[0]-1))/2;
        if(y%2==0)  ans+=(c[y/2]*(c[y/2]-1))/2;
    }
    cout<<ans;nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}