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
    vector<vi> adj(n+1);
    int u,v;
    for(int i=1;i<n;i+=1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi deg(n+1,0);
    ll ans=LLONG_MAX/4,sum=0;
    for(int i=1;i<=n;i+=1){
        sum+=max(0ll,(ll)adj[i].size()-2);
        ll t=0;
        for(int k:adj[i])
            if(adj[k].size()>=2) t+=1;
        ans=min(ans,t-max(0ll,(ll)adj[i].size()-2));
    }
    cout<<ans+sum;nl;
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