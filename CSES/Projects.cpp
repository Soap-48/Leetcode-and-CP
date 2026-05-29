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
    vector<array<ll,3>> a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    map<int,ll> m;
    m[0]=0;
    sort(all(a),[](const array<ll,3> a,const array<ll,3> b){
            return a[1]<b[1];
    });
    for(int i=0;i<n;i+=1){
        auto it=m.upper_bound(a[i][0]-1);
            it=prev(it);
            m[a[i][1]]=max((*m.rbegin()).second,(*it).second+a[i][2]);
    }
    ll ans=0;
    for(auto &[i,j]:m)
        ans=max(ans,j);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}