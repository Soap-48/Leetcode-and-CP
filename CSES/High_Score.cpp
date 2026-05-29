#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
const ll inf=-1e17;
using namespace std;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<array<ll,3>> e(m);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i+=1){
        cin>>e[i][0]>>e[i][1]>>e[i][2];
        adj[e[i][0]].push_back(e[i][1]);
    }
    vll d(n+1,inf);
    d[1]=0;
    for(int j=1;j<n;j+=1)
        for(int i=0;i<m;i+=1)
            if(d[e[i][0]]!=inf)
                d[e[i][1]]=max(d[e[i][1]],d[e[i][0]]+e[i][2]);
    ll ans=d[n];
    queue<int> q;
    vector<int> vis(n+1,0);
    for(int j=0;j<m;j+=1)
        if(d[e[j][0]]!=inf&&d[e[j][1]]<d[e[j][0]]+e[j][2])
            q.push(e[j][1]),vis[e[j][1]]=1;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(int j:adj[i]){
            if(j==n){
                cout<<"-1";
                return;
            }
            if(vis[j]==0){
                vis[j]=1;
                q.push(j);
            }
        }
    }
    cout<<d[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}