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

ll help(int n,int m,vector<string> &ss){
    ll ans=0;
    int si=0,sj=0;
    for(;si<n;si+=1){
        for(sj=0;sj<m;sj+=1)
            if(ss[si][sj]=='X')
                break;
        if(ss[si][sj]=='X')
            break;
    }
    if(si==n){
        return 0;
    }
    for(int i=si;i<n;i+=1)
        for(int j=0;j<sj;j+=1)
            if(ss[i][j]=='X')
                return -1;
    ll a=0,b=-1;
    for(;a+sj<m;a+=1)
        if(ss[si][a+sj]=='.')
            break;
    ll x1=sj,x2=sj+a;
    ll y1=si,y2=si;
    if(x2==m){
        int last=si;
        while(last<n&&ss[last][sj]=='X')
            last+=1;
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(i>=si&&i<last&&j>=sj){
                    if(ss[i][j]=='.')
                        return -1;
                }
                else if(ss[i][j]=='X')
                    return -1;
            }
        }
        return a;
    }
    else{
        while(y1<n&&ss[y1][x1]=='X')
            y1+=1;
        while(y2<n&&ss[y2][x2]=='.')
            y2+=1;
        if(y2==n)
            b=1;
        else{
            b=y1-y2;
        }
        if(b<=0)    return -1;
        pair<int,int> p={si,sj},q={si,sj+a-1},r={si+b-1,sj},s={si+b-1,sj+a-1};
        for(int i=p.first;i<=s.first;i+=1)
            for(int j=p.second;j<=s.second;j+=1)
                if(ss[i][j]=='.')
                    return -1;
        while(s.first<n&&s.second<m){
            if((s.first+1<n&&ss[s.first+1][s.second]=='X')||(s.second+1<m&&ss[s.first][s.second+1]=='X')){
                if(r.first+1<n&&ss[r.first+1][r.second]=='X'){ //down
                    for(int j=r.second;j<=s.second;j+=1){
                        if(ss[r.first+1][j]=='.')
                            return -1;
                    }
                    for(int j=q.second+1;j<m;j+=1)
                        if(ss[q.first][j]=='X')
                            return -1;
                    for(int j=0;j<r.second;j+=1)
                        if(ss[r.first+1][j]=='X')
                            return -1;
                    p.first+=1;q.first+=1;r.first+=1;s.first+=1;
                }
                else if(q.second+1<m&&ss[q.first][q.second+1]=='X'){ //right
                    for(int i=q.first;i<=s.first;i+=1){
                        if(ss[i][q.second+1]=='.')
                            return -1;
                    }
                    for(int i=r.first+1;i<n;i+=1)
                        if(ss[i][r.second]=='X')
                            return -1;
                    for(int i=0;i<q.first;i+=1)
                        if(ss[i][q.second+1]=='X')
                            return -1;
                    p.second+=1;q.second+=1;r.second+=1;s.second+=1;
                }
                else
                    break;
            }
            else{
                break;
            }
        }
        for(int i=s.first+1;i<n;i+=1)
            for(int j=s.second+1;j<m;j+=1)
                if(ss[i][j]=='X')
                    return -1;
        for(int i=s.first+1;i<n;i+=1)
            for(int j=0;j<=s.second;j+=1)
                if(ss[i][j]=='X')
                    return -1;
        for(int i=0;i<=s.first;i+=1)
            for(int j=s.second+1;j<m;j+=1)
                if(ss[i][j]=='X')
                    return -1;
       // cerr<<n<<' '<<m<<' '<<a<<' '<<b<<endl;
        return a*b;
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i+=1)
        cin>>s[i];
    ll v1=help(n,m,s);
    vector<string> ss(m,string(n,'O'));
    for(int i=0;i<m;i+=1)
        for(int j=0;j<n;j+=1)
            ss[i][j]=s[j][i];
    ll v2=help(m,n,ss);
    ll ans=-1;
    if(v1!=-1)  ans=v1;
    if(v2!=-1){
        if(ans==-1)  ans=v2;
        else ans=min(ans,v2);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}