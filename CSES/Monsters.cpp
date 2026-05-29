#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

/*
multi point bfs from monsters to get dist array
then bfs from start, and move on valid paths, maintaining parent array
*/

int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i+=1)
        cin>>s[i];
    queue<pair<int,int>> q;
    vector<vi> d(n,vi(m,-1));
    vector<vector<pair<int,int>>> p(n,vector<pair<int,int>>(m,{-1,-1}));
    int sx,sy;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<m;j+=1)
            if(s[i][j]=='M'){  
                q.push({i,j});
                d[i][j]=0;
            }
            else if(s[i][j]=='A'){
                sx=i;sy=j;
            }
    while(!q.empty()){
        auto &[i,j]=q.front();
        for(int k=0;k<4;k+=1){
            int x=i+dx[k],y=j+dy[k];
            if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='.'&&d[x][y]==-1){
                d[x][y]=d[i][j]+1;
                q.push({x,y});
            }
        }
        q.pop();
    }
    q.push({sx,sy});
    vector<vi> di(n,vi(m,-1));
    di[sx][sy]=0;
    while(!q.empty()){
        int siz=q.size();
        for(int t=0;t<siz;t+=1){
            auto &[i,j]=q.front();
            if(i==0||j==0||i==n-1||j==m-1){
                vector<int> ans;
                int x=i,y=j;
                while(x!=sx||y!=sy){
                    auto [px,py]=p[x][y];
                    if(px<x)    ans.push_back(0);//d
                    else if(px>x)   ans.push_back(1);//u
                    else if(py<y)   ans.push_back(2);//r
                    else ans.push_back(3);//l
                    x=px;y=py;
                }
                cout<<"YES\n"          ;
                cout<<ans.size();
                nl;
                char c[]="DURL";
                for(int u=ans.size()-1;u>=0;u-=1)
                    cout<<c[ans[u]];
                return;
            }
            for(int k=0;k<4;k+=1){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='.'&&di[x][y]==-1){
                    di[x][y]=di[i][j]+1;
                    if(d[x][y]==-1||d[x][y]>di[x][y]){
                        p[x][y]={i,j};
                        q.push({x,y});
                    }
                }
            }
            q.pop();
        }
    }
    cout<<"NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}