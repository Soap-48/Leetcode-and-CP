#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void dfs(int i,vector<vi> &adj,vi &vis){
    for(auto j:adj[i]){
        if(vis[j]==0){
            vis[j]=1;
            dfs(j,adj,vis);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vi> adj(n);
    int u,v;
    for(int i=0;i<m;i+=1){
        cin>>u>>v;
        u-=1;v-=1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi comp;vi vis(n,0);
    for(int i=0;i<n;i+=1){
        if(vis[i]==0){
            comp.push_back(i);
            vis[i]=1;
            dfs(i,adj,vis);
        }
    }
    cout<<comp.size()-1<<"\n";
    for(int i=1;i<comp.size();i+=1)
        cout<<comp[0]+1<<' '<<comp[i]+1<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}