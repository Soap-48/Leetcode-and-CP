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
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vi pos,neg;
    ll z=0;
    for(int i=0;i<n;i+=1)
        if(a[i]==0)
            z+=1;
        else if(a[i]>0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    vi ans(n);
    int p=0,q=0;
    if(z==n){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=0;i<z;i+=1)
        ans[i]=0;
    ll sum=0;
    for(int i=z;i<n;i+=1){
        if(sum<=0){ //||q==neg.size()){ reddudant because total sum is 0
            sum+=pos[p];
            ans[i]=pos[p];
            p+=1;
        }
        else{
            sum+=neg[q];
            ans[i]=neg[q];
            q+=1;
        }
    }
    for(int i=0;i<n;i+=1)
        cout<<ans[i]<<' ';
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