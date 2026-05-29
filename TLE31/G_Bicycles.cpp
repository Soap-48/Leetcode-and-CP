/*
              ...                            
             ;::::;                           
           ;::::; :;                          
         ;:::::'   :;                         
        ;:::::;     ;.                        
       ,:::::'       ;           OOO\         
       ::::::;       ;          OOOOO\        
       ;:::::;       ;         OOOOOOOO       
      ,;::::::;     ;'         / OOOOOOO      
    ;:::::::::`. ,,,;.        /  / DOOOOOO    
  .';:::::::::::::::::;,     /  /     DOOOO   
 ,::::::;::::::;;;;::::;,   /  /        DOOO  
;`::::::`'::::::;;;::::: ,#/  /          DOOO 
:`:::::::`;::::::;;::: ;::#  /            DOOO
::`:::::::`;:::::::: ;::::# /              DOO
`:`:::::::`;:::::: ;::::::#/               DOO
 :::`:::::::`;; ;:::::::::##                OO
 ::::`:::::::`;::::::::;:::#                OO
 `:::::`::::::::::::;'`:;::#                O 
  `:::::`::::::::;' /  / `:#                  
   ::::::`:::::;'  /  /   `#
*/

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
    vector<map<ll,ll>> adj(n+1);
    vll s(n+1);
    ll u,v,w;
    for(int i=0;i<m;i+=1){
        cin>>u>>v>>w;
        if(adj[u][v]==0||adj[u][v]>w){
            adj[u][v]=w;
            adj[v][u]=w;
        }
    }
    for(int i=1;i<=n;i+=1)
        cin>>s[i];
    vector<vll> d(n+1,vll(n+1,1e17));
    set<array<ll,3>> q;
    q.insert({0,1,1});
    d[1][1]=0;
    while(!q.empty()){
        array<ll,3> i=(*q.begin());
        q.erase(q.begin());
        for(auto &[j,k]:adj[i[2]]){
            if(d[i[1]][j]>i[0]+s[i[1]]*k){
                d[i[1]][j]=i[0]+s[i[1]]*k;
                if(s[i[1]]>=s[j]){
                    q.insert({d[i[1]][j],j,j});
                }
                else{
                    q.insert({d[i[1]][j],i[1],j});
                }
            }
        }
    }
    ll ans=1e15;
    for(int i=1;i<=n;i+=1){
        ans=min(ans,d[i][n]);
    }
    cout<<ans<<'\n';
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