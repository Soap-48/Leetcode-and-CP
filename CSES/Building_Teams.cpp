#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

int dfs(int i,vector<vi> &adj,vi &vis,int team){
    vis[i]=team;
    for(int j:adj[i]){
        if (vis[j]==-1) dfs(j,adj,vis,3-team);
        else if(vis[j]==team){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
    }
    return 0;
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
    vi vis(n,-1);
    int team=1;
    for(int i=0;i<n;i+=1)
        if(vis[i]==-1) {dfs(i,adj,vis,team);}
    for(int i=0;i<n;i+=1)
        cout<<vis[i]<<' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}