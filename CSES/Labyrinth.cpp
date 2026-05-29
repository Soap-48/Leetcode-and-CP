#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char dr[]={'L','R','U','D'};

void solve(){
    int n,m;
    cin>>n>>m;
    char g[n][m];
    int rx=0,ry=0;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<m;j+=1)
            cin>>g[i][j];    
    for(int i=0;i<n;i+=1)
        for(int j=0;j<m;j+=1)
            if(g[i][j]=='A'){
                rx=i;ry=j;
                break;
            }  
    // stack<pair<int,int>> s;
    // s.push(make_pair(rx,ry));
    // string path="";
    // vector<vi> vis(n,vi(m,0));
    // vis[rx][ry]=1;
    // while(!s.empty()){
    //     pair<int,int> i=s.top();
    //     s.pop();
    //     if(g[i.first][i.second]=='B'){
    //         cout<<"YES\n";
    //         cout<<path.size();nl;
    //         cout<<path;
    //         return;
    //     }
    //     bool flag=true;
    //     for(int j=0;j<4;j+=1){
    //         int nx=i.first+dx[j],ny=i.second+dy[j];
    //         if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'&&vis[nx][ny]==0){
    //             vis[nx][ny]=1;
    //             flag=false;
    //             path+=dr[j];
    //             s.push({nx,ny});
    //         }
    //     }
    //     if(flag)
    //         path.pop_back();
    // }
    // cout<<"NO";
    queue<pair<int,int>> q;
    q.push({rx,ry});
    vector<vi> vis(n,vi(m,0));
    vector<vector<char>> path(n,vector<char>(m));
    path[rx][ry]='E';
    int ex,ey;
    while(!q.empty()){
        pair<int,int> i=q.front();
        q.pop();
        if(g[i.first][i.second]=='B'){
            ex=i.first;ey=i.second;
        }
        for(int i=0;i<)
    }
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