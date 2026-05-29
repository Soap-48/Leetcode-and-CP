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
const long long MOD = 998244353;
using namespace std;

ll binpow(ll b,ll p){
    ll ans=1;
    ll a=(b%MOD);
    while(p>0){
        if(p%2){
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        p=p/2;
    }
    return ans;
}

void solve(){
    ll n;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll c=0;
    for(int i=0;i<n;i+=1)
        if(a[i]%2==0)
            c+=1;
    ll ans=binpow(2ll,c)-1ll;
    ans=(ans-(c%MOD)+MOD)%MOD;
    ans=(ans-(((c*(c-1))/2)%MOD)+MOD)%MOD;
    ll x=0,y=0,z=0;
    vll dx(2,0),dy(2,0),dz(2,0);
    for(int i=0;i<n;i+=1){
        if(a[i]%2){
            x=(x+y)%MOD;
            x=(x+dy[1])%MOD;
            y=(y+z)%MOD;
            y=(y+dz[1])%MOD;
            dx[1]=(dx[1]+dy[0])%MOD;
            dy[1]=(dy[1]+dz[0])%MOD;
            dx[0]=(dx[0]+1)%MOD;
            dy[0]=(dy[0]+1)%MOD;;
            // if(lx==3)
            //     x=dy[1];
            // if(ly==3)
            //     y=dz[1];
           // if(lx>3)
           // if(ly>3)
        }
        else{
            // if(lz==3)
            //  z=dx[1];
            // if(lz>3)
            z=(z+x)%MOD;
            z=(z+dx[1])%MOD;
            dz[1]=(dz[1]+dx[0])%MOD;
            dz[0]=(dz[0]+1)%MOD;
        }
    }
    ans=(ans+x)%MOD;
    ans=(ans+y)%MOD;
    ans=(ans+z)%MOD;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}