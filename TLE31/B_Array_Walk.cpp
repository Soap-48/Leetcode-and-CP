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
    ll n,k,z;
    cin>>n>>k>>z;
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    // vector<vll> dp(n+1,vll(2,-1));
    // dp[1][0]=a[0];dp[1][1]=a[0];
    // for(int i=1;i<=k;i+=1){
    //     vector<vll> ndp(n+1,vll(2,-1));
    //     for(int j=1;j<=k;j+=1){
    //         if((dp[j][0]!=-1||dp[j][1]!=-1)&&j+1<=n){
    //             ndp[j+1][0]=max(ndp[j+1][0],max(dp[j][0],dp[j][1])+a[j]);
    //         }
    //         if(dp[j][0]!=-1&&j-1>=1&&(i-j+1<=(2*z))){
    //             ndp[j-1][1]=max(ndp[j-1][1],dp[j][0]+a[j-2]);
    //         }
    //     }
    //     dp=ndp;
    // }
    // ll ans=0;
    // for(int i=1;i<=n;i+=1)
    //     ans=max({ans,dp[i][0],dp[i][1]});
    // cout<<ans;
    // nl;
    vll pre(k+2,0);
    for(int i=1;i<=k+1;i+=1)
        pre[i]=pre[i-1]+a[i-1];
    ll ans=pre[k+1];
    for(int i=2;i<=k+1;i+=1){
        for(int j=1;j<=5;j+=1){
            ll val=0;
            int max=k+1-2*j;
            if(i>=max){
                val=pre[max]+(j-1)*(a[i-1]+a[i]);
                val=max(val,pre[max]+)
            }
        }
    }
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