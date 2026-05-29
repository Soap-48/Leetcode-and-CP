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
    ll n,k;
    cin>>n>>k;
    vll a(n);ll ans=0;
    for(int i=0;i<n;i+=1)
        cin>>a[i],ans+=__builtin_popcountll(a[i]);
    ll l=1;int c=0;
    while(l<k)  l=l*2,c+=1;
    vll p(c+1,0);
    for(ll i=0;i<=c;i+=1)
        for(int j=0;j<n;j+=1)
            p[i]+=(!(a[j]&(1LL<<i)));
    for(int i=0;i<=c&&k>0;i+=1){
        if(k>=(p[i]*(1LL<<i)))  {
            ans+=p[i];k-=(p[i]*(1LL<<i));
        }
        else{
            ans+=(k/(1LL<<i));
            k=0;
            break;
        }
    }
    cout<<ans;
    nl;
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