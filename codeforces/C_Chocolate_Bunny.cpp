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
    vll ans(n+1,-1);
    queue<ll> big;
    if(n==1){
        cout<<"! 1"<<endl;
        return;
    }
    for(int i=1;i<n;i+=2){
        ll a,b;
        cout<<"? "<<i<<' '<<i+1<<endl;
        cin>>a;
        cout<<"? "<<i+1<<' '<<i<<endl;
        cin>>b;
        if(a>b){
            ans[i]=a;
            big.push(i+1);
        }
        else{
            ans[i+1]=b;
            big.push(i);
        }
    }
    if(n&1) big.push(n);
    while(big.size()>1){
        int siz=big.size();
        siz-=(siz%2);
        for(int i=1;i<=siz;i+=2){
            ll p=big.front();big.pop();
            ll q=big.front();big.pop();
            ll x,y;
            cout<<"? "<<p<<' '<<q<<endl;
            cin>>x;
            cout<<"? "<<q<<' '<<p<<endl;
            cin>>y;
            if(x>y){
                ans[p]=x;
                big.push(q);
            }
            else{
                ans[q]=y;
                big.push(p);
            }
        }
    }
    ans[big.front()]=n;
    cout<<"! ";
    for(int i=1;i<=n;i+=1)
        cout<<ans[i]<<' ';
    nl;
}

int main() {
        solve();
    return 0;
}