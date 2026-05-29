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
    ll n,q;
    cin>>n>>q;
    map<pair<ll,ll>,ll> m;
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=1;i<n;i+=1){
        m[{i,i}]=0;
        m[{i,i+1}]=abs(a[i]-a[i-1]);
    }
    m[{n,n}]=0;
    // a,a+l-1 l legthn, a,a+l/2-1, a+l/2,a+l-1
    for(int l=4;l<=n;l=l*2){
        for(int i=1;i+l-1<=n;i+=1)
            m[{i,i+l-1}]=gcd(gcd(m[{i,i+l/2-1}],m[{i+l/2,i+l-1}]),abs(a[i+l/2-1]-a[i-1]));
    }
    ll l,r;
    for(int i=0;i<q;i+=1){
        cin>>l>>r;
        ll val=(r-l+1);
        ll j=1;
        while(j<val)
            j=j*2;
        if(j>val)
            j=j/2;
        cout<<gcd(gcd(m[{l,l+j-1}],m[{r-j+1,r}]),abs(a[l+j-2]-a[r-j]))<<' ';
    }
    nl;
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