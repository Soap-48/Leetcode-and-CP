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
    int z=0;
    string s(n,'M');
    int ans=1;
    for(int i=1;i<n;i+=1){
        int val=a[i]-a[i-1];
        if(val==0){
            z+=1;
            if(s[i-1]=='L') s[i]='R';
            else if(s[i-1]=='R')    s[i]='L';
        }
        else if(val==1){
            s[i]='L';
            if(s[i-1]=='R'){
                cout<<"0\n";
                return;
            }
            s[i-1]='L';
        }
        else if(val==-1){
            s[i]='R';
            if(s[i-1]=='L'){
                cout<<"0\n";
                return;
            }
            s[i-1]='R';
        }
        else{
            cout<<"0\n";
            return;
        }
    }
    if(z==n-1){
        if(n%2==0){
            if(a[0]==n/2||a[0]==(1+(n/2))){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else{
            if(a[0]==(n+1)/2){
                cout<<"2\n";
            }
            else{
                cout<<"0\n";
            }
        }
        return;
    }
    else{
        if(s[0]=='M'){
            char c;int l=0;
            for(;l<n;l+=1)
                if(s[l]!='M'){
                    c=s[l];
                    break;
                }
            for(int i=l;i>=0;i-=1){
                s[i]=c;
                if(c=='L')  c='R';
                else if(c=='R') c='L';
            }
        }
          //  cerr<<s<<endl;
        vi le(n+1,0),re(n+1,0);
        for(int i=1;i<=n;i+=1){
            le[i]+=le[i-1];
            if(s[i-1]=='L')   le[i]+=1;
        }
        for(int i=n-1;i>=0;i-=1){
            re[i]+=re[i+1];
            if(s[i]=='R')   re[i]+=1;
        }
        for(int i=0;i<n;i+=1){
            int val=1+le[i]+re[i+1];
            if(val!=a[i]){
                cout<<"0\n";
                return;
            }
        }
    }
    cout<<ans;nl;
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