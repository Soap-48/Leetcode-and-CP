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
    vector<vector<array<ll,2>>> adj(n+1);
    int a,b,c;
    for(int i=0;i<m;i+=1){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll> d(n+1,-1);
    d[1]=0;
    set<array<ll,2>> s;
    s.insert({0,1});
    while(!s.empty()){
        auto [i,j]=*s.begin();
        s.erase(s.begin());
        if(i>d[j]) continue;
        for(auto [x,y]:adj[j]){
            if(d[x]==-1||d[x]>d[j]+y){
                d[x]=d[j]+y;
                s.insert({d[x],x});
            }
        }
    }
    for(int i=1;i<=n;i+=1)
        cout<<d[i]<<' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}