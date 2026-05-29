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

int dfs(int i, vector<vector<int>> &adj,vector<int> &vis,vector<int> &p){
    for(auto j:adj[i]){
        if(j==p[i])    continue;
        if(vis[j]==0){
            vis[j]=1;
            p[j]=i;
            int ret=dfs(j,adj,vis,p);
            if(ret!=-1)
                return ret;
        }
        else{
            int k=i;
            while(k!=-1){
                if(k==j){
                    p[j]=i;
                    return j;
                }
                k=p[k];
            }
        }
    }
    return -1;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int u,v;
    for(int i=0;i<m;i+=1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0),p(n+1,-1);
    int in=-1;
    for(int i=1;i<=n;i+=1){
        if(vis[i]==0){
            vis[i]=1;
            int ret=dfs(i,adj,vis,p);
            if(ret!=-1){
                in=ret;
                break;
            }
        }
    }
    if(in==-1){
        cout<<"IMPOSSIBLE";
    }
    else{
        // for(int i=0;i<n;i+=1)
        //     it=p[it];
        vector<int> ans;
        ans.push_back(in);
        int it=p[in];
        while(it!=in){
            ans.push_back(it);
            it=p[it];
        }
        ans.push_back(in);
        //reverse(all(ans));
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i+=1)
            cout<<ans[i]<<' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}