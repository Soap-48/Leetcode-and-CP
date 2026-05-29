#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 998244353;
using namespace std;

ll calc(ll b,ll x){
    ll res=1;
    while(x){
        if(x&1) res=(res*b)%MOD;
        b=(b*b)%MOD;
        x=x/2;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=0;i<n;i+=1)
        cin>>b[i];
    int p=0,q=0;
    for(int i=0;i<n;i+=1){
        if(a[i]>a[p])   p=i;
        if(b[i]>b[q])   q=i;
        if(a[p]>b[q]){
            cout<<((calc(2,a[p]))+(calc(2,b[i-p])))%MOD;
        }
        else if(a[p]<b[q]){
            cout<<((calc(2,b[q]))+(calc(2,a[i-q])))%MOD;
        }
        else{
            cout<<((calc(2,a[p]))+(calc(2,(max(b[i-p],a[i-q])))))%MOD;
        }
        cout<<' ';
    }
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