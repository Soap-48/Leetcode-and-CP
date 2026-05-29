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

vector<ll> cost(1001,1e15);

void solve(){
    ll n,k;
    cin>>n>>k;
    vi b(n),c(n);
    for(int i=0;i<n;i+=1)
        cin>>b[i];
    for(int i=0;i<n;i+=1)        
        cin>>c[i];
    ll amax=min(k,12*n);
    vector<ll> dp(amax+1,0);
    for(int j=0;j<n;j+=1){
        for(int i=amax;i>=cost[b[j]];i-=1){
            dp[i]=max(dp[i],dp[i-cost[b[j]]]+c[j]);
        }
    }
    cout<<(*max_element(all(dp)));
    nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cost[1]=0;
    for(int i=1;i<1000;i+=1){
        for(int j=1;j<=(1+(i/2));j+=1)
            if(i+(i/j)<=1000) cost[i+(i/j)]=min(cost[i+(i/j)],cost[i]+1);
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}