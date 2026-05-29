#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 998244353;
using namespace std;

ll binexp(ll b,ll a){
    ll res=1;
    while(a){
        if(a&1) res=(res*b)%MOD;
        b=(b*b)%MOD;
        a/=2;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    ll ans=1;
    int a[3];
    for(int i=0;i<n/3;i+=1){
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]!=a[1])
            ans*=1;
        else{
            if(a[1]==a[2])  ans=(ans*3)%MOD;
            else ans=(ans*2)%MOD;
        }
    }
    n=n/6;
    for(int i=1;i<=n;i+=1){
        ans=(ans*(n+i))%MOD;;
        ans=(ans*binexp(i,MOD-2))%MOD;
    }
    cout<<ans;nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}