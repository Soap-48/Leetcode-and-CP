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

vector<ll> ch(vector<int> &a,int l,int r){
    ll si=1,prod=0;
    for(int i=l;i<=r;i+=1){
        if(a[i]<0)  si=si*-1;
        if(a[i]==2||a[i]==-2)   prod+=1;
    }
    if(si==1){
        return {prod,0ll,0ll};
    }
    else{
        int le=prod,re=prod;
        int left=l;
        while(a[left]>0){
            if(a[left]==2){
                le-=1;
            }
            left+=1;
        }
        if(a[left]==-2)    le-=1;
        int right=r;
        while(a[right]>0){
            if(a[right]==2){
                re-=1;
            }
            right-=1;
        }
        if(a[right]==-2)    re-=1;
        if(le>=re){
            return {le,left-l+1,0ll};
        }
        else
            return {re,0ll,r-right+1};
    }
}

void solve(){
    ll n;
    cin>>n;
    vi a(n);
    vi ze;
    ze.push_back(-1);
    for(int i=0;i<n;i+=1){
        cin>>a[i];
        if(a[i]==0) ze.push_back(i);
    }
    ze.push_back(n);
    vll ans={0,n,0};
    for(int i=1;i<ze.size();i+=1){
        int f=ze[i-1]+1,s=ze[i]-1;
        if(f<=s){vll temp=ch(a,f,s);
        if(temp[0]>ans[0]){
            ans=temp;
            ans[1]+=f;
            ans[2]+=(n-1-s);}}
    }
    cout<<ans[1]<<" "<<ans[2];
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