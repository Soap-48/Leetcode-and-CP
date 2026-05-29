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

vll dp(1000001,0);
//vll p(1000001,0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0]=1;dp[1]=2;dp[2]=8;
   // p[1]=3;
    for(int i=2;i<=1000000;i+=1){
        // dp[i]=(5*dp[i-1])%MOD;
        // dp[i]=((dp[i]-(2*(p[i-1])))%MOD+MOD)%MOD;
       // p[i]=(dp[i]+p[i-1])%MOD;
        dp[i]=(6*dp[i-1])%MOD;
        dp[i]=((dp[i]-7*dp[i-2])%MOD+MOD)%MOD;
    }
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        cout<<dp[n];
        nl;
    }
    return 0;
}