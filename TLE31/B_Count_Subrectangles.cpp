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
    ll n,m,k;
    cin>>n>>m>>k;
    vll a(n),b(m);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=0;i<m;i+=1)
        cin>>b[i];
    vll sa(n+1,0),sb(m+1,0);
    ll c=0;
    a.push_back(0);b.push_back(0);
    for(ll i=0;i<=n;i+=1){
        if(a[i]==1) c+=1;
        else{
            for(ll j=1;j<=min(c,n);j+=1)
                sa[j]+=(c-j+1);
            c=0;
        }
    }
    c=0;
    for(ll i=0;i<=m;i+=1){
        if(b[i]==1) c+=1;
        else{
            for(ll j=1;j<=min(c,m);j+=1)
                sb[j]+=(c-j+1);
            c=0;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i+=1){
        if(k%i==0&&(k/i)<=m){
            ans+=(sa[i]*sb[k/i]);
        }
    }
    cout<<ans;
    nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}