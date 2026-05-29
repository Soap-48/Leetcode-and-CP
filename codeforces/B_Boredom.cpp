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
    int n;
    cin>>n;
    map<int,ll> m;
    int k;
    int maxi=0;
    for(int i=0;i<n;i+=1){
        cin>>k;
        m[k]+=1;
        maxi=max(maxi,k);
    }
    vll dp(maxi+1,0);
    ll ans=0;
    for(ll i=1;i<=maxi;i+=1){
        ll l=(i>2?dp[i-2]:0);
        ll r=(i>3?dp[i-3]:0);
        dp[i]=i*m[i]+max(l,r);
        ans=max(ans,dp[i]);
    }
    cout<<ans;nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}