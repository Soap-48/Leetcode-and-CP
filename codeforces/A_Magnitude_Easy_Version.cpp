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
    vi v(n+1);
    for(int i=1;i<=n;i+=1)
        cin>>v[i];
    ll a=0,b=0;
    for(int i=1;i<=n;i+=1){
        ll c=max(abs(a+v[i]),abs(b+v[i]));
        ll d=min(a+v[i],b+v[i]);
        a=c;b=d;
    }
    cout<<a;nl;
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