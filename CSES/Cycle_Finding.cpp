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
    for(int i=0;i<m;i+=1) {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vll d(n+1,0);
    vi p(n+1,-1);
    //d[1]=0;
    for(int i=1;i<n;i+=1){
        for(int j=1;j<=n;j+=1){
            if(d[j]!=1e17)  for(int k=0;k<adj[j].size();k+=1){
                ll v=adj[j][k][0],w=adj[j][k][1];
                if(d[v]>d[j]+w){
                    d[v]=d[j]+w;
                    p[v]=j;
                }
            }
        }
    }
    for(int u=1;u<=n;u+=1){
        if(d[u]!=1e17) for(int i=0;i<adj[u].size();i+=1){
            if(d[adj[u][i][0]]>d[u]+adj[u][i][1]){
                p[adj[u][i][0]]=u;
                int in=u;
                cout<<"YES\n";
                for(int q=0;q<n;q+=1)
                    in=p[in];
                u=in;
                in=p[in];
                vector<int> ans;
                while(in!=u){
                    ans.push_back(in);
                    in=p[in];
                }
                cout<<u<<' ';
                for(auto it=ans.rbegin();it!=ans.rend();it++)
                    cout<<*it<<' ';
                cout<<u;
                return;
            }
        }
    }
    cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}