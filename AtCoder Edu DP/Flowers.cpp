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

using ll = long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define nl cout << '\n'
const int MOD = 1000000007;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n),c(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=0;i<n;i+=1)
        cin>>c[i];
    vector<ll> dp(n+1,0);
    int len=(int)sqrt(n)+1;
    vector<ll> sq(len,0);
    auto query=[&dp,&sq,&len](int r)->ll{
        ll val=dp[0];
        // for(int i=0;i<=r;){
        //     if(i%len==0&&i+len-1<=r){
        //         val=max(val,sq[i/len]);
        //         i+=len;
        //     }
        //     else{
        //         val=max(val,dp[i]);
        //         i+=1;
        //     }
        // } old and slow times-> 25 ms 19ms 18ms 17ms
        int cr=r/len;
        if(cr==0){
            for(int i=1;i<=r;i+=1)
                val=max(val,dp[i]);
        }
        else{
            for(int i=0;i<=cr-1;i+=1)
                val=max(val,sq[i]);
            for(int i=cr*len;i<=r;i+=1)
                val=max(val,dp[i]);
        }
        return val;
    };
    auto update=[&dp,&sq,&len](int i, ll val)->void{
            dp[i]=val;
            sq[i/len]=max(val,sq[i/len]);
    };
    ll ans=0;
    for(int i=0;i<n;i+=1){
        ll val=query(a[i]-1);
        val+=c[i];
        if(val>dp[a[i]]){
            ans=max(ans,val);
            update(a[i],val);
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}