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
    vll a(n),b(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=0;i<n;i+=1)
        cin>>b[i];
    sort(all(a));sort(all(b));
    ll ans=0;
    for(int i=0;i<n;i+=1){
        ll curr=1e10;
        for(int j=0;j<n;j+=1){
            curr=min(curr,abs(a[j]-b[(i+j)%n]));
        }
        ans=max(ans,curr);
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