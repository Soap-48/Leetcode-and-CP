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
    vi x(n),y(n),f(n);
    for(int i=0;i<n;i+=1)
        cin>>x[i];
    for(int i=0;i<n;i+=1)
        cin>>y[i];
    int z=0;
    for(int i=0;i<n;i+=1){
        f[i]=y[i]-x[i];
        if(f[i]==0)
            z+=1;
    }
    sort(all(f));
    ll ans=z/2;
    int l=0;
    while(l<n&&f[l]<0)
        l+=1;
    int r=l;
    while(r<n&&f[r]==0)
        r+=1;
    l-=1;
    if(z&1&&r<n){
        ans+=1;
        r+=1;
    }
    // for(int i=0;i<n;i+=1)
    //     cerr<<f[i]<<' ';
    // cerr<<" | ";
    // cerr<<l+1<<" | "<<r+1<<endl;
    for(int i=l;i>=0&&r<n;i-=1){
        int c=1;
        ll val=f[i];
        if(r<n){
            val+=f[r];
            r+=1;
            c+=1;
        }
        while(r<n&&val<0){
            val+=f[r];
            r+=1;
            c+=1;
        }
        if(val>=0&&c>=2)
            ans+=1;
    }
    ans+=(n-r)/2;
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