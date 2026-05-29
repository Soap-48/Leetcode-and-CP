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
    ll N,a,b;
    cin>>N>>a>>b;
    ll n=a+b;
    if(n==0){
        cout<<"YES\n";
        for(int i=1;i<=N;i+=1)
            cout<<i<<' ';
        nl;
        for(int i=1;i<=N;i+=1)
            cout<<i<<' ';
        nl;
        return;
    }
    if(a<1||a>n-1||b<1||b>n-1||n>N){
        cout<<"NO\n";
    }
    else{
        vector<int> ac(N),bc(N);
        for(int i=a+1;i<=n;i+=1)
            bc[i-a-1]=i;
        for(int i=1;i<=a;i+=1)
            bc[i+n-a-1]=i;
        for(int i=n;i<N;i+=1)
            bc[i]=i+1;
        for(int i=0;i<N;i+=1)
            ac[i]=i+1;
        cout<<"YES\n";
        for(int i=0;i<N;i+=1)
            cout<<ac[i]<<' ';
        nl;
        for(int i=0;i<N;i+=1)
            cout<<bc[i]<<' ';
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