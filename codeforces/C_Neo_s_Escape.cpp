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
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll ans=0;
    vll b;
    b.push_back(a[0]);
    for(int i=1;i<n;i+=1)
        if(a[i]!=a[i-1])    b.push_back(a[i]);
    b.push_back(0);
    for(int i=1;i<b.size()-1;i+=1)
        if(b[i]>b[i-1]&&b[i]>b[i+1])
            ans+=1;
    if(b.size()>1&&b[0]>b[1])   ans+=1;
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