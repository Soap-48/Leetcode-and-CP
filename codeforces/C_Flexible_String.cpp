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
    ll n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    set<char> c(all(a));
    if(k>=c.size()){
        cout<<(n*(n+1))/2;
        nl;
        return;
    }
    ll ans=0;
    for(ll i=(1LL<<k)-1;i<(1LL<<c.size());i+=1){
        if(__builtin_popcount(i)==k)
        {
            ll val=0,curr=0;
            set<char> chu;
            ll j=0;
            for(auto &p:c){
                if((i>>j)&1ll)
                    chu.insert(p);
                j+=1;
            }
            for(int j=0;j<n;j+=1){
                if(a[j]==b[j]||chu.find(a[j])!=chu.end())
                    curr+=1;
                else{
                    val+=(curr*(curr+1))/2;
                    curr=0;
                }
            }
            val+=(curr*(curr+1))/2;
            ans=max(ans,val);
        }
    }
    cout<<ans;
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