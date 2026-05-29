#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

ll help(vi &a,int k,int l,int n){
    map<ll,ll> f;ll c=0;
    ll i=0,j=0;ll ans=0;
    while(j<n){
        c+=1;
        f[a[j]]+=1;
            while(i<=j&&f.size()>k){
                f[a[i]]-=1;c-=1;i+=1;
            }
        if(f.size()==k){
            ans+=max(0ll,j+1-max(i,j+1-l));
        }
        j+=1;
    }
    return ans;
}

void solve(){
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    
    cout<<help(a,k,r,n)-help(a,k,l,n);nl;
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