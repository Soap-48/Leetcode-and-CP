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

int dx[]={0,0,-1,+1};
int dy[]={-1,+1,0,0};

void solve(){
    ll n,m;
    cin>>n>>m;
    int bi,bj,ri,rj;
    vector<string> s(n);
    for(int i=0;i<n;i+=1)
        cin>>s[i];
    for(int i=0;i<n;i+=1){
        if(s[i].find('S')!=s[i].npos){
            bi=i;
            bj=s[i].find('S');
            break;
        }
    }
    //dp[n][m][4][4] row,col,dir,consecutive steps
    vector<vector<vector<vector<ll>>>> dp(n,vector<vector<vector<ll>>>(m,vector<vector<ll>>(4,vector<ll>(4,1e18))));
    dp[bi][bj][0][0]=0;dp[bi][bj][1][0]=0;dp[bi][bj][2][0]=0;dp[bi][bj][3][0]=0;
    queue<array<int,4>> q;
    ll ans=1;
    q.push({bi,bj,-1,0});
    while(!q.empty()){
        int siz=q.size();
        for(int ttt=0;ttt<siz;ttt+=1){
            auto j=q.front();q.pop();
            int r=j[0],c=j[1],dir=j[2];
            for(int i=0;i<4;i+=1){
                int nr=r+dy[i],nc=c+dx[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&s[nr][nc]!='#'){
                    int st=1;
                    if(i==dir) st=j[3]+1;
                    if(st>3)    continue;
                    if(ans<dp[nr][nc][i][st]){
                        dp[nr][nc][i][st]=ans;
                        q.push({nr,nc,i,st});
                    }
                    if(s[nr][nc]=='T'){
                        cout<<ans;
                        nl;
                        return;
                    }
                }
            }
        }
        ans+=1;
    }
    cout<<"-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}




    // vector<vi> vis(n,vi(m,0)),d(n,vi(m,0));
    // vector<vector<pair<int,int>>> state(n,vector<pair<int,int>>(m,{-1,LONG_LONG_MAX/2}));
    // queue<pair<int,int>> q;
    // q.push({bi,bj});
    // state[bi][bj].second=0;
    // ll ans=1;
    // while(!q.empty()){
    //     int siz=q.size();
    //     for(int i=0;i<siz;i+=1){
    //         auto j=q.front();
    //         q.pop();
    //         int r=j.first,c=j.second;
    //         vis[r][c]+=1;
    //         for(int k=0;k<4;k+=1){
    //             int nr=r+dy[k];
    //             int nc=c+dx[k];
    //             if(nr>=0&&nr<n&&nc>=0&&nc<m&&s[nr][nc]!='#'&&vis[nr][nc]<2){
    //                 if(state[r][c].first==k){
    //                     if(state[r][c].second==3)
    //                         continue;
    //                     else{
    //                         state[nr][nc].first=k;
    //                         state[nr][nc].second=min(state[nr][nc].second,state[r][c].second+1);
    //                         d[nr][nc]=ans;
    //                     }
    //                 }
    //                 else{
    //                     if(state[nr][nc].second==1&&d[nr][nc]==ans){
    //                         state[nr][nc].first='N';
    //                         state[nr][nc].second=0;
    //                     }
    //                     else{
    //                         state[nr][nc].first=k;
    //                         state[nr][nc].second=min(state[nr][nc].second,1);
    //                     }
    //                     d[nr][nc]=ans;
    //                 }
                    
    //                 q.push({nr,nc});
    //                 if(s[nr][nc]=='T'){
    //                     cout<<ans;
    //                     nl;
    //                     return;
    //                 }
    //             }
    //         }
    //     }
    //     ans+=1;
    // }
    // cout<<"-1\n";