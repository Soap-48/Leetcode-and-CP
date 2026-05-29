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
    ll n,m;
    cin>>n>>m;
    vector<vll> adj(n+1);
    ll u,v;
    for(int i=0;i<m;i+=1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i+=1)
        sort(all(adj[i]));
    ll ans=0,i=1,j=1;
    while(j<=n){
        auto it=lower_bound(all(adj[j]),i);
        if(it!=adj[j].end()&&((*it)<=j)){
            i+=1;
            while(i<=j){
                auto itt=lower_bound(all(adj[j]),i);
                if(itt==adj[j].end()||((*itt)>j))
                    break;
                i++;
            }
        }
        ans+=(j-i+1);
        j+=1;
    }
    // ll l=n+1-i;
    // ans+=(l*(l+1))/2;
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