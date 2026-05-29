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
    ll n;
    cin>>n;
    vll a(n+1);a[n]=0;
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll ans=1e14;
    ll i=0,j=0;
    while(j<=n){
        if(a[i]!=a[j]){
            ans=min(ans,a[i]*(n+i-j));
            i=j;
        }
        j+=1;
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