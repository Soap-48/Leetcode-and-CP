/*
              ...                             
             ;::::;                           
           ;::::; :;                          
         ;:::::'    :;                        
        ;:::::;     ;.                        
       ,:::::'       ;           OOO\         
       ::::::;       ;          OOOOO\        
       ;:::::;       ;         OOOOOOOO       
      ,;::::::;     ;'        / OOOOOOO       
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
const ll MOD=1000000007;
using namespace std;

void solve(){
    string s;int d;
    cin>>s;
    cin>>d;
    vector<vector<vll>> dp(2,vector<vll>(10,vll(d,0)));
    dp[1][0][0]=1;
    for(int i=0;i<s.size();i+=1){
        vector<vector<vll>> ndp(2,vector<vll>(10,vll(d,0)));
        int dig=s[i]-'0';
        for(int j=0;j<10;j+=1)
            for(int k=0;k<10;k+=1)
                for(int l=0;l<d;l+=1){
                    ndp[0][j][(l+j)%d]+=dp[0][k][l];
                    ndp[0][j][(l+j)%d]%=MOD;
                    if(j<=dig){
                        if(j==dig){
                            ndp[1][j][(l+j)%d]+=dp[1][k][l];
                            ndp[1][j][(l+j)%d]%=MOD;
                        }
                        else{
                            ndp[0][j][(l+j)%d]+=dp[1][k][l];
                            ndp[0][j][(l+j)%d]%=MOD;
                        }
                    }
                }
        dp=ndp;
    }
    ll ans=0;
    for(int i=0;i<10;i+=1){
        ans+=dp[0][i][0];
        ans%=MOD;
        ans+=dp[1][i][0];
        ans%=MOD;
    }
    ans=((ans-1)%MOD+MOD)%MOD;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}