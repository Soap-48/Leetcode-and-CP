#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void dfs()

void solve(){
    int n;
    cin>>n;
    vector<vi> adj(n);
    int u,v;
    for(int i=1;i<n;i+=1){
        cin>>u>>v;
        u-=1;v-=1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi deg1;vi ans(n-1,-1);
    for(int i=0;i<n;i+=1)
        if(adj[i].size()==1)
            deg1.push_back(i);
    if(deg1.size()==n)
    int a=deg1[0],b=deg1[1];
    
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