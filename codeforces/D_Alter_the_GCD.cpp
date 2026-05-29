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
    vll a(n),b(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=0;i<n;i+=1)
        cin>>b[i];
    vll pa(n+1),sa(n+1),pb(n+1),sb(n+1);
    pa[0]=0;pb[0]=0;
    for(int i=1;i<=n;i+=1){
        pa[i]=gcd(pa[i-1],a[i-1]);
        pb[i]=gcd(pb[i-1],b[i-1]);
    }
    sa[n]=0;sb[n]=1;
    for(int i=n-1;i>=0;i-=1){
        sa[i]=gcd(sa[i+1],a[i]);
        sb[i]=gcd(sb[i+1],b[i]);
    }
    ll max=0;vll ans;
    for(int i=0;i<n;i+=1){
        ll val1=gcd(gcd(pa[i],sa[i+1]),b[i]);
        ll val2=gcd(gcd(pb[i],sb[i+1]),a[i]);
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