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
    vll a(n+1),vis(n+1,1);
    for(int i=1;i<=n;i+=1)
        cin>>a[i];
    vector<vi> adj(n+1);
    int u,v;
    for(int i=1;i<n;i+=1){
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vll mi(n+1,1e15),ma(n+1,0);
    mi[1]=a[1],ma[1]=a[1];
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        vis[i]=0;
        for(int j:adj[i]){
            if(vis[j]){
                mi[j]=min(a[j],a[j]-ma[i]);
                ma[j]=max(a[j],a[j]-mi[i]);
                q.push(j);
            }
        }
    }
    for(int i=1;i<=n;i+=1)
        cout<<ma[i]<<' ';
    nl;
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