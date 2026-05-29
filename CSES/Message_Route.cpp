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
    int n,m;
    cin>>n>>m;
    vector<vi> adj(n);
    vi vis(n,0),parent(n,-1),dist(n,1);
    int u,v;
    vis[0]=1;
    for(int i=0;i<m;i+=1){
        cin>>u>>v;
        u-=1;v-=1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int i=q.front();q.pop();
        for(int j:adj[i]){
            if(!vis[j]){
                vis[j]=1;
                dist[j]=dist[i]+1;
                q.push(j);
                parent[j]=i;
            }                
        }
    }
    if(vis[n-1]!=0){
        cout<<dist[n-1];nl;
                int k=n-1;
                vi ans;
                while(k!=-1){
                    ans.push_back(k+1);
                    k=parent[k];
                }
                for(int oasdpf=ans.size()-1;oasdpf>=0;oasdpf-=1)
                    cout<<ans[oasdpf]<<' ';
    }
    else cout<<"IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}