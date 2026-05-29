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
    ll n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll ans=0;
    // if(n&1){
    //     for(int i=0;i<n;i+=1){
    //         if(a[(n-1)/2][i]!=a[i][(n-1)/2])
    //             ans+=1;
    //     }
    // }
    for(int i=0;i<n/2;i+=1){
        for(int j=0;j<(n+1)/2;j+=1){
            int x=0,y=0;
            if(a[i][j]=='1')
                x+=1;
            else
                y+=1;
            if(a[j][n-1-i]=='1')
                x+=1;
            else
                y+=1;
            if(a[n-1-i][n-1-j]=='1')
                x+=1;
            else
                y+=1;
            if(a[n-1-j][i]=='1')
                x+=1;
            else
                y+=1;
            ans+=min(x,4-x);
        }
    }
    cout<<ans;nl;
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