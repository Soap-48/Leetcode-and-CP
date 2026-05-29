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
    int x;
    cin>>x;
    int lo=-1,hi=1e4;
    while(hi-lo>1){
        int m=(lo+hi)/2;
        int val=(m*(m-1))/2;
        if(val>=x)
            hi=m;
        else
        lo=m;
    }
    int n=lo;
    int i=x-((n*(n-1))/2);
    ll ans=0;
    ll l=i,r=i;
    for(ll it=n;it>0;it-=1){
        ll val=(it*(it-1))/2;
        ans+=((val+r)*(val+r+1ll)*((val+r)*2ll+1ll))/6ll;
        ans-=((val+l-1ll)*(val+l)*((val+l)*2ll-1ll))/6ll;
        l=max(1ll,l-1);
        r=min(r,it-1);
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