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
    vector<vector<pair<int,int>>> adj(n+1);
    vll dp(n+1,-1),active(n+1,1e8);
    active[1]=0;dp[1]=1;
    int u,v;
    for(int i=1;i<n;i+=1){
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(auto [i,j]:adj[a]){
            if(dp[i]==-1){
                q.push(i);
                if(j>=active[a]){
                    dp[i]=dp[a];
                }
                else{
                    dp[i]=dp[a]+1;
                }
                active[i]=j;
            }
        }
    }
    cout<<(*max_element(all(dp)));nl;
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