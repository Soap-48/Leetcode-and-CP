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
    vector<vi> adj(n+1);
    vll in(n+1,0),d(n+1,0);
    for(int i=0;i<m;i+=1){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        in[v]+=1;
    }
    queue<int> q;
    for(int i=1;i<=n;i+=1)
        if(in[i]==0)
            q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        ans.push_back(i);
        for(int j:adj[i]){
            in[j]-=1;
            if(in[j]==0)
                q.push(j);
        }
    }
    d[1]=1;
    int s=find(all(ans),1)-ans.begin();
    for(int it=s;it<n;it+=1){
        if(d[ans[it]]!=-1e6)
            for(int i:adj[ans[it]]){
                    d[i]=(d[i]+d[ans[it]])%MOD;
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