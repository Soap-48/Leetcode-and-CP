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

vector<int> prime(300001,1);

void solve(){
    ll n;
    cin>>n;
    vector<int> a(300001,0);
    vector<int> arr(n+1);
    map<int,int> m;
    vector<int> p(300001,-1);
    ll c;
    for(int i=1;i<=n;i+=1){
        cin>>c;
        arr[i]=c;
        m[c]=i;
        a[c]=1;
    }
    ll ss,tt;
    cin>>ss>>tt;
    ll s=arr[ss],t=arr[tt];
    if(ss==tt){
        cout<<"1\n"<<ss;
        return;
    }
    if(s==1||t==1){
        cout<<"-1";
        return;
    }
    if(gcd(s,t)!=1){
        cout<<"2\n";
        cout<<ss<<' '<<tt;
        return;
    }
    if(!prime[s])   a[s]=0;
    ll ans=1;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        int siz=q.size();
        for(int i=0;i<siz;i+=1){
            ll j=q.front();
            q.pop();
           // a[j]=0;
            if(j==t){
                cout<<ans;
                nl;
                vector<ll> bac;
                ll it=t;
                while(it!=s){
                    it=p[it];
                    bac.push_back(it);
                }
                cout<<ss;
                for(int ppp=bac.size()-2;ppp>=0;ppp-=1){
                    cout<<' '<<m[bac[ppp]];
                }
                cout<<' '<<tt;
                return;
            }
            for(ll d=1;d*d<=j;d+=1){
                if(j%d==0){
                    if(prime[d]){
                        prime[d]=0;
                        for(int e=d;e<=300000;e+=d){
                            if(a[e]==1){
                                a[e]=0;
                                p[e]=j;
                                q.push(e);
                            }
                        }
                    }
                    if(prime[j/d]){
                        prime[j/d]=0;
                        for(int e=j/d;e<=300000;e+=(j/d)){
                            if(a[e]==1){
                                a[e]=0;
                                p[e]=j;
                                q.push(e);
                            }
                        }
                    }
                }
            }
        }
        ans+=1;
    }
    cout<<-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prime[1]=0;
    for(int i=2;i*i<=300000;i+=1){
        if(prime[i]==1){
            for(int j=i*i;j<=300000;j+=i)
                prime[j]=0;
        }
    }
        solve();
    return 0;
}