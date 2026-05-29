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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    if(n==2){
        if(s[1]>=s[0]){
            for(int i=0;i<m;i+=1)
                cout<<s[0];
            nl;
        }
        else{
            for(int i=0;i<m/2;i+=1)
                cout<<s;
            if(m&1)
                cout<<s[0];
            nl;
        }
        return;
    }
    if(n==1){
        for(int i=0;i<m;i+=1)
            cout<<s[0];
        nl;
        return;
    }
    vector<ll> p(n+1);
    p[0]=0;
    for(int i=0;i<n;i+=1)
        p[i+1]=p[i]+(s[i]-'a');
    int ans=n-1;
    for(int i=0;i<n-1;i+=1){
        if(s[i+1]>s[0]){
            ans=i;
            break;
        }
        else if(s[i+1]==s[0]){
            ll l=i+1,r=lcm(n,i+1)+1;
            while(r-l>1){
                ll m=(l+r)/2;
                ll v1=(p[n]*(m/n))+(p[m%n]);
                ll v2=(p[i+1]*(m/(i+1)))+p[(m)%(i+1)];
                if(v1==v2)
                    l=m;
                else
                    r=m;
            }
            if(s[(l+1)%n]>s[(l+1)%(i+1)]){
                ans=i;
                break;
            }
        }
    }
    ans+=1;
    for(int i=0;i<m;i+=1)
        cout<<s[i%ans];
    nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}