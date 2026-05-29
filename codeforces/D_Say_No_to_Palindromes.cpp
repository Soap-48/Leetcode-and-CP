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
    string s;
    cin>>s;
    vector<vector<ll>> cost(6,vector<ll>(n+1,0));
    vector<string> km={"abc","bca","cab","acb","bac","cba"};
    for(int j=0;j<6;j+=1){
        for(int i=0;i<n;i+=1)
            if(s[i]!=km[j][i%3]) cost[j][i+1]=cost[j][i]+1;
            else cost[j][i+1]=cost[j][i];
    }
    int l,r;
    for(int i=0;i<m;i+=1){
        cin>>l>>r;
        ll ans=1e15;
        for(int j=0;j<6;j+=1)
            ans=min(ans,cost[j][r]-cost[j][l-1]);
        cout<<ans;nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}