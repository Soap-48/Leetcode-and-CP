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

vector<int> a;
int lg[200001];
ll st[30][200001];
int mini=1000000000,maxi=-1;
map<int,vector<int>> m;
int dp[200001];

inline int ret(int i,int j){
    if(i>j)
        return -1;
    int l=lg[j-i+1];
    return max(st[l][i],st[l][j-(1<<(l))+1]);
}

int solve(int i, int l, int r){
    if(dp[i]!=0)
        return dp[i];
    else{
        if(l>r||i<l||i>r)
            return -111111;
        if(a[i]==mini)
            dp[i]=1;
        else{
            int m1=ret(l,i-1);
            int m2=ret(i+1,r);
            int v1=0,v2=0;
            if(m1!=-1){
                auto x1=lower_bound(all(m[m1]),l);
                auto y1=lower_bound(all(m[m1]),i);
                for(;x1!=y1;++x1){
                        v1=max(v1,solve((*x1),l,i-1));
                        //cerr<<"1: "<<j<<endl;
                }
                if(m1==a[i])
                    v1-=1;
            }
            if(m2!=-1){
                auto x2=upper_bound(all(m[m2]),i);
                auto y2=upper_bound(all(m[m2]),r);
                //y=next(y);
                for(;x2!=y2;++x2){
                        v2=max(v2,solve((*x2),i+1,r));
                        //cerr<<"2: "<<j<<endl;
                }
                if(m2==a[i])
                    v2=-1;
            }
            
            dp[i]=1+max(v1,v2);
        }
        return dp[i];
    }
}

void solve(){
    lg[1]=0;
    ll n;
    cin>>n;

    int k,last=-1;
    for(int i=0;i<n;i+=1){
        cin>>k;
        if(k!=last){
            last=k;
            a.push_back(k);
        }
    } 
    n=a.size();

    for(int i=0;i<n;i+=1){
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
        m[a[i]].push_back(i);
    }

    for(int i=2;i<=n;i+=1)
        lg[i]=lg[i/2]+1;

    for(int i=0;i<n;i+=1)
        st[0][i]=a[i];
    for(int i=1;i<=lg[n];i+=1)
        for(int j=0;j+(1<<i)<=n;j+=1)
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);

    int ans=-100000000;
    for(int i=0;i<(int)m[maxi].size();i+=1){
        int l=0,r=n-1;
        if(i>0) l=m[maxi][i-1]+1;
        if(i+1<m[maxi].size())  r=m[maxi][i+1]-1;
        ans=max(ans,solve(m[maxi][i],l,r));
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}