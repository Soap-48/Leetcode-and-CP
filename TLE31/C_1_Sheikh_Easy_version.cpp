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
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vll ps(n+1),px(n+1);
    vll nxt(n+1,-1);
    nxt[n]=n-1;
    for(int i=n-1;i>=1;i-=1){
        if(a[i-1]!=0)
            nxt[i]=i;
        else
            nxt[i]=nxt[i+1];
    }
    ps[0]=0;px[0]=0;
    for(int i=0;i<n;i+=1){
        ps[i+1]=ps[i]+a[i];
        px[i+1]=px[i]^a[i];
    }
    ll l,r;
    for(int i=0;i<q;i+=1){
        cin>>l>>r;
        ll a1=l,a2=r;
        ll val=ps[r]-ps[l-1]-(px[r]^px[l-1]);
        for(int j=l;j<=r;j+=1){
            ll lo=j,hi=r;
            ll pp=r;
            if(val==(ps[r]-ps[j-1]-(px[r]^px[j-1]))){
                while(hi-lo>=0){
                ll m=(lo+hi)/2;
                ll op=ps[m]-ps[j-1]-(px[m]^px[j-1]);
                if(val==op){
                    pp=m;
                    hi=m-1;
                }
                else
                    lo=m+1;
            }
            if(pp-j<a2-a1){
                a1=j;
                a2=pp;
            }
            }
            else
                break;
        }
       // cerr<<a1<<' '<<a2<<endl;
        cout<<a1<<' '<<a2;
        nl;
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