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
    int k,a,b,x,y;
    cin>>k>>a>>b>>x>>y;
    if(y>x){
        swap(x,y);
        swap(a,b);
    }
    ll ans=0;
    if(k>=b)    ans=1+(k-b)/y;
    k-=ans*y;
    if(k>=a)    ans+=(1+(k-a)/x);
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