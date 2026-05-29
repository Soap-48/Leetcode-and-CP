#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const long long MOD = 1000000007;
const long long inf=1e18;
using namespace std;

//matrix power with binary exponentiation -> n3logn
//floyd warsal n3

void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vll> adj(n+1,vll(n+1,inf));
    int a,b;
    ll c;
    for(int i=0;i<m;i+=1)    {
        cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[a][b],c);
    }
    for(int i=1;i<=n;i+=1)  adj[i][i]=0;
    for(int i=1;i<=n;i+=1){
        for(int j=1;j<=n;j+=1){
            for(int k=1;k<=n;k+=1){
                if(adj[j][k]>adj[j][i]+adj[i][k])
                    adj[j][k]=adj[j][i]+adj[i][k];
            }
        }
    }
    for(int i=0;i<q;i+=1){
        cin>>a>>b;
        if(adj[a][b]==inf)
            cout<<-1;
        else
            cout<<adj[a][b];
        nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}

//took 3 attemts
//1st mistake inf too small
//2nd mistake didnt intialize adj[i][i] as 0