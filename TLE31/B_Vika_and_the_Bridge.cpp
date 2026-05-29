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
    vll last(k+1,0);
    vector<pair<ll,ll>> step(k+1,{0,0});
    step[0].first=1e6;step[0].second=1e6;
    ll c;
    for(int i=1;i<=n;i+=1){
        cin>>c;
        if(i-last[c]-1>=step[c].first){
            step[c].second=step[c].first;
            step[c].first=i-last[c]-1;
        }
        else if(i-last[c]-1>=step[c].second){
            step[c].second=i-last[c]-1;
        }
        last[c]=i;
    }
    for(int i=1;i<=k;i+=1)
        if(n-last[i]>=step[i].first){
            step[i].second=step[i].first;
            step[i].first=n-last[i];
        }
        else if(n-last[i]>=step[i].second){
            step[i].second=n-last[i];
        }
    //sort(all(step));
    ll ans=1e6;
    for(int i=1;i<=k;i+=1){
        ans=min(ans,max(step[i].first/2,step[i].second));
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