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

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const ll MOD=1000000007;
using namespace std;

int n;

vector<vll> mul(const vector<vll> &a,const vector<vll> &b){
    vector<vll> c(n,vll(n,0));
    for(int i=0;i<n;i+=1)
        for(int j=0;j<n;j+=1)
            for(int k=0;k<n;k+=1){
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]%=MOD;
            }
    return c;
}

vector<vll> binpow(vector<vll> a,ll b){
    vector<vll> res=a;
    while(b>0){
        if(b%2==1)
            res=mul(res,a);
        a=mul(a,a);
        b=b/2;
    }
    return res;
}

void solve(){
    ll k;
    cin>>n>>k;
    vector<vll> m(n,vll(n));
    for(int i=0;i<n;i+=1)
        for(int j=0;j<n;j+=1)
            cin>>m[i][j];
    vector<vll> ans=binpow(m,k-1);
    ll val=0;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<n;j+=1){
            val+=ans[i][j];
            val%=MOD;
        }
    cout<<val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}