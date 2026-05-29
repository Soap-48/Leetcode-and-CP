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
    int a;
    vector<set<int>> adj(n+1);
    for(int i=1;i<=n;i+=1){
        cin>>a;
        adj[i].insert(a);
        adj[a].insert(i);
    }
    int sum=n*2;
    for(set<int> &s:adj)
        sum-=s.size();
    vi vis(n+1,0);

    int c=0;
    for(int it=1;it<=n;it+=1){
        if(!vis[it]){
            c+=1;
            queue<int> q;q.push(it);
            while(!q.empty()){
                int i=q.front();
                q.pop();
                vis[i]=1;
                for(int j:adj[i]){
                    if(!vis[j]){
                        q.push(j);
                    }
                }
            }
        }
    }
    int op=sum/2,cl=c-op;
    cout<<cl+(op!=0)<<' '<<op+cl;nl;
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