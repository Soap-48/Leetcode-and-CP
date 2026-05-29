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

int n;

void solve(){
    cin>>n;
    vector<vll> dp(n,vll((1<<n),-1));
    vector<vi> adj(n);
    int val;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<n;j+=1){
            cin>>val;
            if(val==1){
                adj[i].push_back(j);
               // adj[j].push_back(i);
            }
        }
    auto solve=[&dp,&adj](auto &s,int i,int j)->ll{
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0){
            for(int &k:adj[0]){
                if(j&(1<<k)){
                    return dp[0][j]=1;
                }
            }
            return dp[0][j]=0;
        }
        ll val=0;
        for(int &k:adj[i])
            if(j&(1<<k))
                val=(val+s(s,i-1,j&(~(1<<k))))%MOD;
        return dp[i][j]=val;        
    };
    solve(solve,n-1,(1<<n)-1);
    if(dp[n-1][(1<<n)-1]==-1)
        cout<<"0\n";
    else{
        cout<<dp[n-1][(1<<n)-1];
        nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}