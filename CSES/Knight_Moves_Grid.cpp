#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

//since going to and coming from is symmetric for chess
//i will find min moves to reach each cell
// form top left
//dp victim
//but why is it in introductor?
// O(n2) => 1e6 
//iteration order weird so recursive dp

//knight has 8 moves

//man what am i even doing, shit, this shhould be dfs 
//type iteration, my mind is just not clear now for some
//reason

//fuck dfs, me win min we go bfs
// thats the things I have to work on focus during 
//interview, I would have struglled alone
//but the feeling of being observed
//it hinders ,me

void solve(){
    int n;
    cin>>n;
    int dx[]={-2,-1,+1,+2,-2,-1,+1,+2};
    int dy[]={-1,-2,-2,-1,+1,+2,+2,+1};
    vector<vector<int>> grid(n,vector<int>(n,-1));
    grid[0][0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
        for(int k=0;k<8;k+=1){
            int x=i+dx[k],y=j+dy[k];
            if(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==-1){
                grid[x][y]=grid[i][j]+1;
                q.push({x,y});
            }
        }
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1)
            cout<<grid[i][j]<<' ';
        nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}
//ending the stream