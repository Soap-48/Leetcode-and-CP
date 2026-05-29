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
    ll n,qu;
    cin>>n;
    vll a(n);
    for(int i=0;i<n;i+=1){
        cin>>a[i];
    }
    cin>>qu;
    ll maxi=(*max_element(all(a)));
    map<ll,ll> ans;
    map<ll,ll> q;
    q[0]=1;
    for(int i=0;i<n;i+=1){
        map<ll,ll> nq;
        nq[0]=1;
        for(auto &[j,k]:q){
            ll val=gcd(a[i],j);
            ans[val]+=k;
            nq[val]+=k;
        }
        q=nq;
    }
    int v;
    for(int i=0;i<qu;i+=1){
        cin>>v;
        if(v<=maxi)
        cout<<ans[v];
        else
        cout<<"0";
        nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}